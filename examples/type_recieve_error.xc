#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;

  spawn printTwice(ch);

  char j = <-ch;

  return 0; 
}

int printTwice (chan int ch2) {
    ch2 <- 1;
    return 0;
}