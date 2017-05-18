#include <stdlib.h>
#include "../../lib/go_concurrency.xh"
#include <pthread.h>
#include <stdio.h>

int main (int argc, char **argv) {

  Channel<int> *ch = chan_open<int>();

  select {
      case <-ch: 
        printf("Should not occur\n");
      default:
        printf("Default\n");  
  }

  return 0; 
}
