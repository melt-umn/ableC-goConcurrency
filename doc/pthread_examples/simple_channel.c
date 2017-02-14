// This example passes a simple channel to the thread
// For simplicity, I am assuming that the channel has
// a value of int and there is no queue for for incoming
// send or recieve requests.  Channel is always open.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

typedef struct __SimpleChannel {
    int value;
    pthread_cond_t* cond;
    pthread_mutex_t mtx;
    // status is 
    // 0 for nothing waiting
    // 1 for waiting to send
    // 2 for waiting to recieve
    int status;
} SimpleChannel;


SimpleChannel createChannel(){
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    SimpleChannel ch = {
        0,
        NULL,
        mtx,
        0
    };
    return ch;
}


void send(SimpleChannel* ch, int v){
    pthread_mutex_lock(&(ch->mtx));
    // If waiting to recieve
    if(ch->status==2){
        // set value to v
        ch->value = v;
        // set status to waiting
        ch->status = 0;
        // wake up waiting reciever
        pthread_mutex_unlock(&(ch->mtx));
        pthread_cond_signal(ch->cond);
        return;
    }
    // if already waiting to send
    else if(ch->status==1){
        // do nothing
        return;
    }
    // if nothing is ready to recieve
    else{
        ch->status = 1;
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
        ch->cond = &cond;
        // set value to v
        ch->value = v;
        // go to sleep until a reciever is found
        pthread_cond_wait(&cond,&(ch->mtx));
        pthread_mutex_unlock(&(ch->mtx));
        return;
    }
}

int recieve(SimpleChannel* ch){
    pthread_mutex_lock(&(ch->mtx));
    int ret;
    // If waiting to send
    if(ch->status==1){
        // set status to waiting
        ch->status = 0;
        // set value to v
        ret = ch->value;
        // wake up waiting sender
        pthread_mutex_unlock(&(ch->mtx));
        pthread_cond_signal(ch->cond);
        return ret;
    }
    // if already waiting to recieve
    else if(ch->status==2){
        // do nothing
        return 0;
    }
    // if nothing is ready to send
    else{
        ch->status = 2;
        pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
        ch->cond = &cond;
        // go to sleep until a sender is found
        pthread_cond_wait(&cond,&(ch->mtx));
        // set value to v
        ret = ch->value;
        pthread_mutex_unlock(&(ch->mtx));
        return ret;
    }
}

void* doSomething( void* arg ){
    SimpleChannel* ch = (SimpleChannel*) arg;
    int foo = recieve(ch);
    printf("Recieved: %d\n",foo);
}
 
int main(){
    SimpleChannel ch = createChannel();
    pthread_t thread;
    printf("started!\n");
    pthread_create(&thread, NULL, doSomething, &ch );
    send(&ch,13);
    send(&ch,69);
    pthread_join(thread, NULL);
}