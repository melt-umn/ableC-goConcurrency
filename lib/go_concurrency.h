
#ifndef GO_CONCURRENCY_H
#define GO_CONCURRENCY_H

#include <pthread.h>
#include <stdlib.h>

// spawn_routine
// ---
// Should begin some thread executing start_function 
// concurrently with the thread it is called from. 
//
// start_function: whatever function should begin executing
// args: a pointer to the arguments start_function will take.
//
void spawn_routine(void*(*start_function) (void *), void *args);

// An OpQueue represents a linked list 
// of waiting channel operations. 
typedef struct __OpQueue {
    // Instead of a boolean, we have a pthread cond object
    pthread_cond_t *cond;
    struct __OpQueue *next; 
} OpQueue;

typedef struct __Channel { 
    void *v;
    int closed;
    OpQueue *recvq;
    OpQueue *sendq;
    pthread_mutex_t lock;
    pthread_cond_t vcond;
} Channel;

// chan_open
// ---
//
// returns: an initialized Channel
Channel *chan_open();

// chan_close
// ---
// Frees the memory in a Channel. 
// 
// In Go, closing a channel does more than free it--
// specifically it prevents any thread from sending
// or receiving on it, and anything that is looping
// over a channel will stop doing so. The channel 
// loop is a part of a language feature in Go for many
// loopable data types, and isn't currently a part of
// the scope of this extension.
//
// ch: The channel to be freed
void chan_close(Channel *ch);

// chan_send
// ---
// Attempts to send v to a receiver along ch.
// If v is not of the type the receiver expects, has
// undefined behavior. When compiled through silver, 
// this possibility will throw a compilation error.
// If no receiver is available, will block until one
// is.
//
// ch: The channel to send v through
// v: the value to be sent
void chan_send(Channel *ch, void *v);

// chan_recv
// ---
// Attempts to obtain a value from ch.
// Parallel to send. Blocks until a sender is available.
//
// ch: The channel to wait for a value on
void *chan_recv(Channel *ch);

// chan_recv_select
// ---
// Works as chan_recv, but the value recieved (if any)
// is stored in v, and returns whether any value was 
// available. Does not block.
int chan_recv_select(Channel *ch, void **v);

// chan_send_select
// ---
// Works as chan_send, but returns whether any value was 
// sent. Does not block.
int chan_send_select(Channel *ch, void *v);

#endif