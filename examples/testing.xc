#include <stdio.h>
#include "../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

int main(){
  Channel<int>* ch = chan_open<int>();
  (<-ch);
  spawn(spawn_test, 3, 4)
  chan_close<int>(ch);
}

void spawn_test(int a, int b) {}
