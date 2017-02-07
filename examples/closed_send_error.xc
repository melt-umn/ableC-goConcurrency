#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;
  chan int ch2 = open chan;

  close ch2;
  spawn example(ch2);

  <-ch;

  return 0; 
}

int example (chan int ch2) {
    ch2 <- 1;
    return 0;
}