#include <stdio.h>

int main (int argc, char **argv) {


  chan int ch = open int chan;
  // Channel<int>* ch = chan_open<int>()
  chan int ch2 = open chan;

  spawn func(chan int ch, chan int ch2) {
    ch <- <-ch2;
  }(ch, ch2);

  while(true) {
    select {
        case <-ch:
            printf("Channel One\n");
            break;
        case ch2 <- 1:
            printf("Channel Two\n");
    }
  }

  return 0; 
}
