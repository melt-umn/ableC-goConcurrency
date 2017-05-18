#include <stdio.h>
#include "../../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

void *example (Channel<char>* ch2) {
    ch2 <- 'k';
}

int main (int argc, char **argv) {

  Channel<char>* ch = chan_open<char>();

  spawn(example,ch);

  double *j = <-ch;

  printf("%f\n", *j);

  return 0; 
}