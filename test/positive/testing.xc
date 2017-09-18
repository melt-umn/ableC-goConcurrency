#include <stdio.h>
#include "../../include/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

void *spawn_test(Channel<int>* ch, int a, int b) {
  printf("%d,%d\n",a,b);
  printf("End spawn test\n");
  ch <- 0;
}

int main(){
  Channel<int>* ch = chan_open<int>();
  spawn(spawn_test, ch, 5, 4);
  close(ch);
}


