
#ifndef GO_CONCURRENCY_H
#define GO_CONCURRENCY_H

#include <pthread.h>
#include <stdlib.h>

// This routine spawning could go in a second header
void spawn_routine(void*(*start_function) (void *), void *args);

typedef struct __ThreadQueue {
    // Instead of a boolean, we have a pthread cond object
    pthread_cond_t *cond;
    struct __ThreadQueue *next; 
} ThreadQueue;

ThreadQueue *new_thread_queue();

typedef struct __Channel { 
    void *v;
    int closed;
    ThreadQueue *recvq;
    ThreadQueue *sendq;
    pthread_mutex_t lock;
    pthread_cond_t vcond;
} Channel;

Channel *open_chan();

void chan_close(Channel *ch);

void chan_send(Channel *ch, void *v);

void *chan_recv(Channel *ch);

// Tries are used for select statements,
// and should be incorporated in non-try
// calls to avoid duplicating logic. 

int try_chan_send(Channel *ch, void *v);

int try_chan_recv(Channel *ch);

#endif