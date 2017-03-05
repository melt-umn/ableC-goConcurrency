#include <stdio.h>
#include "../lib/go_concurrency.h"

int main(){
  Channel* ch = open chan;
  int a = 90;
  ch->v = (void*) &a;
  printf("%d\n",*((int*)(ch->v)));
  // Problem now, this 4 needs to be put in a local variable
  // before we can send it through here, otherwise the cast 
  // (I believe) attempts to cast the integer constant which
  // fails. Might not be an issue after templating.
  ch <- 4;
  close(ch);
}