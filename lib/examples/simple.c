#include <stdlib.h>
#include "../go_concurrency.h"
#include <pthread.h>
#include <stdio.h>

void *testfunc(void* args) {
    printf( "I am inside the thread\n");
    // args should be automatically cast in
    // a compilation step   
    Channel *ch = (Channel*)args;
    int send = 70;
    // ch <- send;
    chan_send(ch, (void*)send);
    send++;
    chan_send(ch, (void*)send);
}

int main( int argc, char** argv ) {
    Channel *ch = chan_open();
    spawn_routine(testfunc, ch);
    printf("Main is trying to receive.\n");
    // int returned = <-ch;
    int returned = (int)chan_recv(ch);
    printf("Result %d \n",returned);
    int returned2 = (int)chan_recv(ch);
    printf("Result %d \n",returned2);
    chan_close(ch);
}