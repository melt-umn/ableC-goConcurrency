#include <stdio.h>

int main (int argc, char **argv) {

  chan int ch = open chan;

  select {
      case <-ch: 
        printf("Should not occur");
      default:  
  }

  return 0; 
}
