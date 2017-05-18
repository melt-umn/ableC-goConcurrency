#include <stdio.h>
#include "../../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

int example (Channel<int> *ch2) {
    ch2 <- 1;
    return 0;
}

int main () {

  Channel<int> *ch2 = chan_open<int>();
  close(ch2);

  spawn(example, ch2);

  Channel<int> *ch = chan_open<int>();

  <-ch;

  return 0; 
}