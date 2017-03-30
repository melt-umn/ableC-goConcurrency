#include <stdlib.h>
#include "../go_concurrency.xh"
#include <pthread.h>
#include <stdio.h>

// Adapted from https://golang.org/doc/play/sieve.go

typedef struct __filter_args {
  Channel<int> *in;
  Channel<int> *out;
  int prime;  
} filter_args;

// Send the sequence 2, 3, 4, ... to channel 'ch'.
void *generate(void* args) {
    //
    // chan int ch = make chan;
    //
    Channel<int> *ch = (Channel<int>*)args;
	int i = 2;
    while (1) {
		ch <- i; 
        i++;
	}
}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
void *filter(void* args) {
    filter_args *f_args = (filter_args*)args;
    Channel<int> *in = f_args->in;
    Channel<int> *out = f_args->out;
    int prime = f_args->prime;
    // The above should be generated in a wrapper function
    while (1) {
        int i = (<-in);
		if ((i%prime) != 0) {
			out <- i; 
		}
	}
}

// The prime sieve: Daisy-chain Filter processes.
int main( int argc, char** argv ) {
    Channel<int>* ch1 = open chan<int>;
    //
    //spawn generate(ch1);
    //
    spawn_routine(generate, ch1);
    int i;
    for (i = 1; i < 101; i++) {
		int prime = (<-ch1);
        printf("The %dth prime is: %d\n", i, prime);
        Channel<int>* ch2 = open chan<int>;
        //
        //spawn filter(ch1, ch2, prime)
        //
        filter_args *f_args = malloc(sizeof(filter_args));
        f_args->in = ch1;
        f_args->out = ch2;
        f_args->prime = prime;
        spawn_routine(filter, f_args);
        ch1 = ch2;
	}
}