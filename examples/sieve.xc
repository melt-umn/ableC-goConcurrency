#include <stdlib.h>
#include "../lib/go_concurrency.xh"
#include <pthread.h>
#include <stdio.h>

// Adapted from https://golang.org/doc/play/sieve.go

// Send the sequence 2, 3, 4, ... to channel 'ch'.
void *generate(Channel<int>* ch) {
	int i = 2;
    while (1) {
        ch <- i; 
        i++;
	}
}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
void *filter(Channel<int>* in, Channel<int>* out, int prime) {
    while (1) {
        int i = ( <- in ); 
        if ((i % prime) != 0) {
          out <- i; 
        }
	}
}

// The prime sieve: Daisy-chain Filter processes.
int main( int argc, char** argv ) {
    Channel<int>* ch = chan_open<int>();
    spawn(generate, ch);
    int i;
    for (i = 1; i < 1001; i++) {
		int prime = ( <- ch );
        printf("The %dth prime is: %d\n", i, prime);
        Channel<int>* ch1 = chan_open<int>();
        spawn(filter, ch, ch1, prime);
        ch = ch1;
	}
}