#include <stdio.h>
#include "../../include/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

Channel<int>* ch1;
Channel<int>* ch2;

void *spawn_test1(int a, int b) {
  printf("%d,%d\n",a,b);
  int i = 0;
  while(i < 2000000000){i++;}
  ch1 <- 1;
}

void *spawn_test2(int a, int b) {
  printf("%d,%d\n",a,b);
  int i = 0;
  while(i < 1000000000){i++;}
  ch2 <- 1;
}

int main(){
  ch1 = chan_open<int>();
  ch2 = chan_open<int>();
  int cow = 25;
  spawn(spawn_test1, cow, 2);
  spawn(spawn_test2, 3, 4);
  int i;
  int j;
  for(i = 0; i < 2; i++){
    select {
      case <-ch2: printf("Channel Two\n");

      case j =<-ch1: printf("Channel %d\n", j);

      case ch1 <- 5: printf("Channel Three\n");
    }
  }
  chan_close<int>(ch1);
  chan_close<int>(ch2);
}


