
#include <stdlib.h>
#include "go_concurrency.h"
#include <pthread.h>
#include <stdio.h>


Channel *make_chan() {
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
    Channel *c = malloc(sizeof(Channel));
    c->v = NULL;
    c->closed = 0;
    c->recvq = new_thread_queue();
    c->sendq = new_thread_queue();
    c->lock = &lock;
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

int try_chan_send_locked(Channel *ch, void *v) {
    pthread_cond_t *recv_cond = ch->recvq->cond;
    
    if (recv_cond != NULL) {
        // If there is a reciever waiting for a value,
        // drop that reciever from the queue to claim it. 
        ch->recvq = ch->recvq->next;
        if (ch->recvq = NULL) {
            ch->recvq = new_thread_queue();
        }
        // Set the value of this channel to be the 
        // value sent in, then unlock that reciever's
        // thread so they can properly recieve it.
        ch->v = v;
        // Wake the waiting reciever up
        pthread_cond_signal(recv_cond);
        return 1;
    }
    return 0;
}

int try_chan_send(Channel *ch, void *v) {
    pthread_mutex_lock(ch->lock);
    int b = try_chan_send_locked(ch, v);
    pthread_mutex_unlock(ch->lock);
    return b;
}

void chan_send(Channel *ch, void *v) {
    if (try_chan_send(ch, v)) {
        return;
    }
    // If no reciever is waiting for a value,
    // this routine needs to wait until one
    // shows up so it can send v to it and
    // sync up. 

    // This implementation uses a conditional
    // wait until there is an available reciever.
    
    // Go to end of sendq
    ThreadQueue *send_lock = ch->sendq;
    while (send_lock->next != NULL) {
        send_lock = send_lock->next;
    }
    send_lock->next = new_thread_queue();
    send_lock = send_lock->next; 
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
    send_lock->cond = &cond;
    
    pthread_mutex_lock(ch->lock);
    // cond_wait unlocks, and locks again after it returns
    pthread_cond_wait(send_lock->cond,ch->lock);
    try_chan_send_locked(ch, v);
    pthread_mutex_unlock(ch->lock);
    return;
}

int try_chan_recv_locked(Channel *ch) {
    pthread_cond_t *send_cond = ch->sendq->cond;
    
    if (send_cond != NULL) {
        // If there is a sender waiting,
        // drop that sender from the queue to claim it. 
        ch->sendq = ch->sendq->next;
        if (ch->sendq = NULL) {
            ch->sendq = new_thread_queue();
        }
        // Wake the waiting sender up
        pthread_cond_signal(send_cond);
        return 1;
    }
    return 0;
}

int try_chan_recv(Channel *ch) {
    pthread_mutex_lock(ch->lock);
    int b = try_chan_recv_locked(ch);
    pthread_mutex_unlock(ch->lock);
    return b;
}

void *chan_recv(Channel *ch) {
    if (try_chan_recv(ch)) {
        void *ret_v = ch->v;
        return ret_v;
    }
    
    // Go to end of recvq
    ThreadQueue *recv_lock = ch->recvq;
    while (recv_lock->next != NULL) {
        recv_lock = recv_lock->next;
    }
    recv_lock->next = new_thread_queue();
    recv_lock = recv_lock->next; 
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
    recv_lock->cond = &cond;

    pthread_mutex_lock(ch->lock);
    // cond_wait unlocks, and locks again after it returns
    pthread_cond_wait(recv_lock->cond,ch->lock);
    try_chan_recv_locked(ch);
    void *ret_v = ch->v; 
    pthread_mutex_unlock(ch->lock);
    return ret_v;
}

void *testfunc(void* args) {
    printf( "I am inside the thread\n");   
    Channel *ch = (Channel*)args;
    int send = 5;
    chan_send(ch, &send);
}

int main( int argc, char** argv ) {
    Channel *ch = make_chan();
    spawn_routine(testfunc, ch);
    //try_chan_recv(ch);
    //int returned = *(int*)chan_recv(ch);
    //printf("Result %d \n",returned);
    sleep(3);
}