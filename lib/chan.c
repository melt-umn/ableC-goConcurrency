
#include <stdlib.h>
#include "go_concurrency.h"
#include <pthread.h>
#include <stdio.h>


Channel *make_chan() {
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
    Channel *c = malloc(sizeof(Channel));
    c->v = NULL;
    c->closed = 0;
    c->recvq = new_thread_queue();
    c->sendq = new_thread_queue();
    c->lock = lock;
    c->vcond = cond;
    return c;
} 

ThreadQueue *new_thread_queue() {
    ThreadQueue *tq = malloc(sizeof(ThreadQueue));
    tq->cond = NULL;
    tq->next = NULL;
    return tq;
}

void spawn_routine(void*(*start_function) (void *), void *args) {
    pthread_t thread;
    pthread_create(&thread, NULL, start_function, args );
    return; 
}

int try_chan_send(Channel *ch, void *v) {
    pthread_cond_t *recv_cond = ch->recvq->cond;
    
    if (recv_cond != NULL) {
        printf("send has found a receiver\n");
        // If there is a receiver waiting for a value,
        // drop that receiver from the queue to claim it. 
        ch->recvq = ch->recvq->next;
        if (ch->recvq = NULL) {
            ch->recvq = new_thread_queue();
        }
        // Set the value of this channel to be the 
        // value sent in, then unlock that receiver's
        // thread so they can properly receive it.
        ch->v = v;
        // Wake the waiting receiver up
        pthread_cond_signal(recv_cond);
        
        return 1;
    };
    printf("send has not found a receiver\n");
    return 0;
}

void chan_send(Channel *ch, void *v) {
    pthread_mutex_lock(&(ch->lock));
    if (try_chan_send(ch, v)) {
        pthread_mutex_unlock(&(ch->lock));
        return;
    }
    // If no receiver is waiting for a value,
    // this routine needs to wait until one
    // shows up so it can send v to it and
    // sync up. 

    // This implementation uses a conditional
    // wait until there is an available receiver.
    
    // Go to end of sendq
    ThreadQueue *send_lock = ch->sendq;
    while (send_lock->next != NULL) {
        send_lock = send_lock->next;
    }
    send_lock->next = new_thread_queue();

    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
    send_lock->cond = &cond;
    
    // cond_wait unlocks, and locks again after it return
    printf("Send is waiting for receiver\n");
    pthread_cond_wait(send_lock->cond,&(ch->lock));
    printf("Send has woken for receiver\n");
    ch->v = v;
    printf("Send has placed value into ch->v\n");
    pthread_cond_signal(&(ch->vcond));
    printf("Send has told receive its value is ready\n");
    pthread_mutex_unlock(&(ch->lock));
    return;
}

int try_chan_recv(Channel *ch) {
    pthread_cond_t *send_cond = ch->sendq->cond;
    
    if (send_cond != NULL) {
        printf("receive has found a send cond\n");
        // If there is a sender waiting,
        // drop that sender from the queue to claim it. 
        ch->sendq = ch->sendq->next;
        if (ch->sendq = NULL) {
            ch->sendq = new_thread_queue();
        }
        printf("receive is trying to wake up sender\n");
        pthread_cond_signal(send_cond);
        printf("receive has woken up sender\n");
        pthread_cond_wait(&(ch->vcond),&(ch->lock));
        printf("receive has been informed its value is ready\n");
        return 1;
    }
    printf("receive has not found a sender\n");
    return 0;
}

void *chan_recv(Channel *ch) {
    pthread_mutex_lock(&(ch->lock));
    if (try_chan_recv(ch)) {
        printf("ch->v = %d\n",*((int*)(ch->v)));
        void *ret_v = ch->v;
        pthread_mutex_unlock(&(ch->lock));
        return ret_v;
    }
    
    // Go to end of recvq
    ThreadQueue *recv_lock = ch->recvq;
    while (recv_lock->next != NULL) {
        recv_lock = recv_lock->next;
    }
    recv_lock->next = new_thread_queue();

    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
    recv_lock->cond = &cond;
    printf("Receive is waiting for a sender\n");
    // cond_wait unlocks, and locks again after it returns
    pthread_cond_wait(recv_lock->cond,&(ch->lock));
    void *ret_v = ch->v; 
    printf("Receive has been woken up\n");
    pthread_mutex_unlock(&(ch->lock));
    return ret_v;
}

void *testfunc(void* args) {
    printf( "I am inside the thread\n");   
    Channel *ch = (Channel*)args;
    int send = 69;
    chan_send(ch, &send);
    // Without this sleep, the output is always 0.
    sleep(1);
}

int main( int argc, char** argv ) {
    Channel *ch = make_chan();
    spawn_routine(testfunc, ch);
    printf("Main is trying to receive.\n");
    int returned = *(int*)chan_recv(ch);
    printf("Result %d \n",returned);
}