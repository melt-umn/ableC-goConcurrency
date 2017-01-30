#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;

  spawn func(chan int ch2) {
    ch2 <- 1;
  };

  <-ch;

  return 0; 
}
