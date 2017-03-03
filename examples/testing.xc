#include <stdio.h>
#include "../lib/go_concurrency.h"

int main(){
  Channel* ch = open chan;
  int a = 90;
  ch->v = (void*) &a;
  printf("%d\n",*((int*)(ch->v)));
}