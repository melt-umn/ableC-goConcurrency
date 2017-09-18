#include <stdio.h>
#include "../../include/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

void *example (Channel<int>* ch2) {
    ch2 <- "string";
}

int main (int argc, char **argv) {

  Channel<char>* ch = chan_open<char>();

  spawn(example,ch);
  <-ch;

  return 0; 
}