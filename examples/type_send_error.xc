#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;

  spawn example(ch);
  <-ch;

  return 0; 
}

int example (chan int ch2) {
    ch2 <- "string";
    return 0;
}