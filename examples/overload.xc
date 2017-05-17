#include <stdlib.h>
#include "../lib/go_concurrency.xh"
#include <pthread.h>
#include <stdio.h>

// Interesting: We can't include this, as it defines
// a function called close, which ableC thinks is our close
// keyword. This makes sense, as close is used similarly to 
// a function, but it introduces a critical problem-- are
// exentsions inherently incompatible with libraries that 
// try to define functions using their kewywords?
//#include <unistd.h>

// Overload attempts to demonstrate that the channel lock system
// will not overwrite values senders are putting through with other
// sender's values prior to the former values being received.

// A failure of this test would be known if the same value was printed
// twice, or if any value from 0-59 is not printed.

void *send20(Channel<int>* ch, int start) {
	int i;
	for (i = start; i < start+20; i++) {
		ch <- i;
	}
}

int printId = 0;

void *printReceive(Channel<int>* ch)  {
	int printArray[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int i;
	int id = ++printId;
	while(1) {
		// We collect results in groups of ten to prevent
		// any synchronization that printf might cause
		for (i = 0; i < 10; i++) {
			printArray[i] = <-ch;
		}
		for (i = 0; i < 10; i++) {
			printf("Out on %d: %d \n",id,printArray[i]);
		}
	}
}

int main( int argc, char** argv ) {
    Channel<int> *ch = chan_open<int>();
	spawn(send20, ch, 0);
	spawn(send20, ch, 20);
	spawn(send20, ch, 40);
	spawn(printReceive, ch);
	spawn(printReceive, ch);
	int i;
	while(i < 2000000000){i++;}
}