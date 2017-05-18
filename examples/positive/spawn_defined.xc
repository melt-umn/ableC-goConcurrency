#include <stdio.h>
#include "../../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

void *printTwice (Channel<int>* ch2, int b) {
    printf("Spawned Print\n");
    ch2 <- 1;
    printf("Race Print\n");
}

int main () {
  printf("First Print\n");
  Channel<int>* ch = chan_open<int>();
  spawn(printTwice, ch, 4);
  printf("Second Print\n");
  <-ch;
  return 0; 
}