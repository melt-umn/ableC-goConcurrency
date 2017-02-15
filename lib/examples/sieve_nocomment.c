#include <stdlib.h>
#include "../go_concurrency.h"
#include <pthread.h>
#include <stdio.h>

typedef struct __filter_args {
  Channel *in;
  Channel *out;
  int prime;  
} filter_args;

// Send the sequence 2, 3, 4, ... to channel 'ch'.
//void *generate(ch chan int) {
void *generate(void* args) {
    Channel *ch = (Channel*)args;
	int i = 2;
    while (1) {
        chan_send(ch, (void*)i); // Send 'i' to channel 'ch'.
        i++;
	}
}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
void *filter(void* args) {
    filter_args *f_args = (filter_args*)args;
	Channel *in = f_args->in;
    Channel *out = f_args->out;
    int prime = f_args->prime;
    while (1) {
        int i = (int)chan_recv(in); // Receive value from 'in'.
		if ((i%prime) != 0) {
            chan_send(out, (void*)i); // Send 'i' to 'out'.
		}
	}
}

// The prime sieve: Daisy-chain Filter processes.
int main( int argc, char** argv ) {
    Channel *ch = make_chan();
    spawn_routine(generate, ch);
    int i;
    for (i = 1; i < 101; i++) {
        int prime = (int)chan_recv(ch);
        printf("The %dth prime is: %d\n", i, prime);
        Channel *ch1 = make_chan();
        filter_args *f_args = malloc(sizeof(filter_args));
        f_args->in = ch;
        f_args->out = ch1;
        f_args->prime = prime;
        spawn_routine(filter, f_args);
        ch = ch1;
	}
}