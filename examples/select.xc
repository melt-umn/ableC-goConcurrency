#include <stdio.h>

int main (int argc, char **argv) {


  chan int ch = open chan;
  chan int ch2 = open chan;

  spawn func(chan int ch, chan int ch2) {
    ch <- <-ch2;
  }(ch, ch2);

  while(true) {
    select {
        case <-ch:
            printf("Channel One");
            break;
        case ch2 <- 1:
            printf("Channel Two");
    }
  }

  return 0; 
}
