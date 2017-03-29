#include <stdio.h>
#include "../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

int main(){
  Channel<int>* ch = chan_open<int>();
  ch <- 4;
  chan_close<int>(ch);
}
