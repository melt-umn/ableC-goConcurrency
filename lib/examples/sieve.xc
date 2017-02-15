#include <stdlib.h>
#include "../go_concurrency.h"
#include <pthread.h>
#include <stdio.h>

// Adapted from https://golang.org/doc/play/sieve.go

// Send the sequence 2, 3, 4, ... to channel 'ch'.
void *generate(ch chan int) {
	int i = 2;
    while (1) {
		ch <- i; 
        i++;
	}
}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
void *filter(in chan int, out chan int, prime int) {
    while (1) {
        int i = <-in 
		if ((i%prime) != 0) {
			out <- i; 
		}
	}
}

// The prime sieve: Daisy-chain Filter processes.
int main( int argc, char** argv ) {
    chan int ch = make chan;
    spawn generate(ch);
    int i;
    for (i = 1; i < 101; i++) {
		int prime = <-ch;
        printf("The %dth prime is: %d\n", i, prime);
        chan int ch1 = make chan;
        spawn filter(ch, ch1, prime)
        ch = ch1;
	}
}