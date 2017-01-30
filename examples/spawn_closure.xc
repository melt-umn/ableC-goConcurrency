#include <stdio.h>

int main (int argc, char **argv) {

  printf("First Print");

  chan int ch = open chan;

  spawn func(chan int ch2) {
    printf("Spawned Print");
    ch2 <- 1;
    printf("Third Print");
  }(ch);

  printf("Second Print");
  <-ch;

  return 0; 
}
