#include <stdio.h>
#include "../lib/go_concurrency.xh"
#include <stdlib.h>
#include <pthread.h>
int main (int argc, char **argv) {

  spawn(example, 0);

  return 0; 
}
