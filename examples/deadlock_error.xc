#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;
  chan int ch2 = open chan;

  spawn example(ch2);

  // Main routine locks
  <-ch;
  // Neither routine can unlock, deadlock occurs

  return 0; 
}

int example (chan int ch2) {
    // Secondary routine locks;
    ch2 <- 1;
    return 0;
}