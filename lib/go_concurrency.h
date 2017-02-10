
#ifndef GO_CONCURRENCY_H
#define GO_CONCURRENCY_H

#include <stdbool.h>
#include <ctype.h>

// This routine spawning could go in a second header
void spawn_routine(void*(*start_function) (void *));

typedef struct __Channel { 
    void *v;
    bool closed;
    ThreadQueue *recvq;
    ThreadQueue *sendq;
    pthread_mutex_t lock;
} Channel;

typedef struct __ThreadQueue {
    // Instead of a boolean, we have a pthread cond object
    pthread_cond_t *cond;
    struct __ThreadQueue *next; 
} ThreadQueue;


Channel *open_chan();

int close_chan(Channel *ch);

int send_chan(Channel *ch, void *v);

void *recv_chan(Channel *ch);

// Tries are used for select statements,
// and should be incorporated in non-try
// calls to avoid duplicating logic. 

bool try_send_chan(Channel *ch, void *v);

bool try_recv_chan(Channel *ch);

#endif