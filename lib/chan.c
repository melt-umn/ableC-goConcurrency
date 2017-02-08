

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

void chan_send(*Channel ch, *Value v) {
    Value *v2 = ch->v;
    if (v2->type != v->type) {
        // Panic
    }
    while (true) {
        
        pthread_mutex_lock(ch->lock);
        bool *recv_lock = ch->recvq->first;
        if (recv_lock != NULL) {
            // If there is a reciever waiting for a value,
            // drop that reciever from the queue to claim it. 
            ch->recvq = recv_lock->next;
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
            recv_lock = false;
            return;
        }
        pthread_mutex_unlock(ch->lock)

        // If no reciever is waiting for a value,
        // this routine needs to wait until one
        // shows up so it can send v to it and
        // sync up. 

        // This implementation uses a shared 
        // boolean as a lock. This seems like
        // it shouldn't work. The core idea is
        // that the thread needs to lock itself
        // inside something until another thread
        // comes to unlock it. 
        bool *send_lock = ch->sendq->first;
        while (send_lock->first != NULL) {
            send_lock = send_lock->next;
        }
        send_lock = &true;
        
        while (send_lock) {}
    }
}