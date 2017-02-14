#include <stdlib.h>
#include "../go_concurrency.h"
#include <pthread.h>
#include <stdio.h>

// Adapted from https://golang.org/doc/play/sieve.go

// This would be auto-generated
//
typedef struct __filter_args {
  Channel *in;
  Channel *out;
  int prime;  
} filter_args;
//

// Send the sequence 2, 3, 4, ... to channel 'ch'.
//void *generate(ch chan int) {
void *generate(void* args) {
    //
    // chan int ch = make chan;
    //
    Channel *ch = (Channel*)args;
	int i = 2;
    while (1) {
		//ch <- i; 
        chan_send(ch, (void*)i); // Send 'i' to channel 'ch'.
        i++;
	}
}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
//void *filter(in chan int, out chan int, prime int) {
void *filter(void* args) {
    filter_args *f_args = (filter_args*)args;
	Channel *in = f_args->in;
    Channel *out = f_args->out;
    int prime = f_args->prime;
    // The above should be generated in a wrapper function
    while (1) {
        //
        //int i = <-in 
        //
        int i = (int)chan_recv(in); // Receive value from 'in'.
		if ((i%prime) != 0) {
            //
			//out <- i; 
            //
            chan_send(out, (void*)i); // Send 'i' to 'out'.
		}
	}
}

// The prime sieve: Daisy-chain Filter processes.
int main( int argc, char** argv ) {
    // chan int ch = make chan;
    Channel *ch = make_chan();
    // spawn generate(ch)
    spawn_routine(generate, ch);
    int i;
    for (i = 1; i < 101; i++) {
        //
		//int prime = <-ch;
        //
        int prime = (int)chan_recv(ch);
        printf("The %dth prime is: %d\n", i, prime);
		//
        //chan int ch1 = make chan;
        //
        Channel *ch1 = make_chan();
		//
        //spawn filter(ch, ch1, prime)
        //
        filter_args *f_args = malloc(sizeof(filter_args));
        f_args->in = ch;
        f_args->out = ch1;
        f_args->prime = prime;
        spawn_routine(filter, f_args);
		//
        ch = ch1;
	}
}