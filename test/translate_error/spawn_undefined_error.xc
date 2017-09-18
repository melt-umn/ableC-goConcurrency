#include <stdio.h>
#include "../../include/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>

int main (int argc, char **argv) {

  spawn(example, 0);

  return 0; 
}
