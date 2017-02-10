

#include <pthread.h>
#include <chan.h>

*Channel make_int_chan() {
    Channel c = {
        v: {
            intType,
            0,
        },
        closed: false,
        recvq: {
            NULL,
            NULL,
        },
        sendq: {
            NULL,
            NULL,
        }
        lock: PTHREAD_MUTEX_INITIALIZER 
    }
} 

bool try_chan_send_locked(*Channel ch, *Value v) {
    pthread_cond_t *recv_cond = ch->recvq->cond;
    
    if (recv_cond != NULL) {
        // If there is a reciever waiting for a value,
        // drop that reciever from the queue to claim it. 
        ch->recvq = ch->recvq->next;
        if (ch->recvq = NULL) {
            ch->recvq = {
                NULL,
                NULL,
            }
        }
        // Set the value of this channel to be the 
        // value sent in, then unlock that reciever's
        // thread so they can properly recieve it.
        ch->v = v;
        // Wake the waiting reciever up
        pthread_cond_signal(recv_cond);
        return true;
    }
    return false;
}

bool try_chan_send(*Channel ch, *Value v) {
    pthread_mutex_lock(ch->lock);
    bool b = try_chan_send_locked(ch, v);
    pthread_mutex_unlock(ch->lock);
    return b;
}

void chan_send(*Channel ch, *Value v) {
    Value *v2 = ch->v;
    if (try_send_chan(ch, v)) {
        return
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
    send_lock->cond = &PTHREAD_COND_INITIALIZER;
    
    pthread_mutex_lock(ch->lock);
    // cond_wait unlocks, and locks again after it returns
    pthread_cond_wait(send_lock->cond,ch->lock);
    try_chan_send_locked(ch, v);
    pthread_mutex_unlock(ch->lock);
    return
}