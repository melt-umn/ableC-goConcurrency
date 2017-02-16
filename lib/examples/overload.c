#include <stdlib.h>
#include "../go_concurrency.h"
#include <pthread.h>
#include <stdio.h>

// Overload attempts to demonstrate that the channel lock system
// will not overwrite values senders are putting through with other
// sender's values prior to the former values being received.

// A failure of this test would be known if the same value was printed
// twice, or if any value from 0-59 is not printed.

void *send1(void *args) {
	Channel *ch = (Channel*)args;
	int i;
	for (i = 0; i < 20; i++) {
		chan_send(ch, (void*)i);
	}
}

void *send2(void *args) {
	Channel *ch = (Channel*)args;
	int i;
	for (i = 20; i < 40; i++) {
		chan_send(ch, (void*)i);
	}
}

void *send3(void *args) {
	Channel *ch = (Channel*)args;
	int i;
	for (i = 40; i < 60; i++) {
		chan_send(ch, (void*)i);
	}
}

int printId = 0;

void *printReceive(void *args)  {
	Channel *ch = (Channel*)args;
	int printArray[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int i;
	int id = ++printId;
	while(1) {
		// We collect results in groups of ten to prevent
		// any synchronization that printf might cause
		for (i = 0; i < 10; i++) {
			printArray[i] = (int)chan_recv(ch);
		}
		for (i = 0; i < 10; i++) {
			printf("Out on %d: %d \n",id,printArray[i]);
		}
	}
}

int main( int argc, char** argv ) {
    Channel *ch = chan_open();
    spawn_routine(send1, ch);
	spawn_routine(send2, ch);
	spawn_routine(send3, ch);
	spawn_routine(printReceive, ch);
	spawn_routine(printReceive, ch);
	sleep(10);
}