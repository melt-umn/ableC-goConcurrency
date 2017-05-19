#include <stdio.h>
#include "../../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

// Preventing sends and recieves on closed channels
// is not yet implemented

int main () {

  Channel<int> *ch = chan_open<int>();
  close(ch);
  <-ch;

  return 0; 
}