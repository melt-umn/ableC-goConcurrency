#include <stdio.h>

int main (int argc, char **argv) {

  printf("First Print\n");

  chan int ch = open chan;

  spawn func(chan int ch2) {
    printf("Spawned Print\n");
    ch2 <- 1;
    printf("Third Print\n");
  }(ch);

  printf("Second Print\n");
  <-ch;

  return 0; 
}
