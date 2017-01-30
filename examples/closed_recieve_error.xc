#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;
  close ch;
  <-ch;

  return 0; 
}