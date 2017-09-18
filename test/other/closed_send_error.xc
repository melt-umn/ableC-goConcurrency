#include <stdio.h>
#include "../../include/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

// Preventing sends and recieves on closed channels
// is not yet implemented

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