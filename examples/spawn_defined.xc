#include <stdio.h>

int main (int argc, char **argv) {

  printf("First Print");

  chan int ch = open chan;

  spawn printTwice(ch);

  printf("Second Print");
  <-ch;

  return 0; 
}

int printTwice (chan int ch2) {
    printf("Spawned Print");
    ch2 <- 1;
    printf("Third Print");
    return 0;
}