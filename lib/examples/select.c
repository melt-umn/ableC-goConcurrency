#include <stdio.h>
#include "../go_concurrency.h"
#include <stdlib.h>

// See ../../examples/select.xc for equivalent

typedef struct __passThrough_args {
	Channel *to;
	Channel *from;
} passThrough_args;

void *passThrough(void *args) {
	passThrough_args *pta = (passThrough_args*)args;
	chan_send(pta->to, chan_recv(pta->from));
}

int main (int argc, char **argv) {

  Channel *ch1 = chan_open();
  Channel *ch2 = chan_open();
  Channel *unused_channel = chan_open();

  passThrough_args *pta = malloc(sizeof(passThrough_args));
  pta->to = ch1;
  pta->from = ch2;

  spawn_routine(passThrough,pta);

  int i = 45;
  while(1) {
	int v;
	if (chan_recv_select(ch1, &v)) {
		printf("Channel One got: %d\n", v);
		break;
	} else if (chan_recv_select(unused_channel, &v)) {
		printf("Should not be printed\n");
	} else if (chan_send_select(ch2, (void *)i)) {
		printf("Channel Two\n");
	}
  }

  chan_close(ch1);
  chan_close(ch2);

  return 0; 
}
