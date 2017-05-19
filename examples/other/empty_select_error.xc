#include <stdlib.h>
#include "../../lib/go_concurrency.xh"
#include <pthread.h>
#include <stdio.h>

int main (int argc, char **argv) {

  // The error here is an infinite loop, which is technically valid,
  // so this is a positive example but one which we don't want to run 
  // without a timeout. 
  select {};

  return 0; 
}
