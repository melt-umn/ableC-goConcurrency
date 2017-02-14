EDIR = ./examples

all: chan.o $(EDIR)/sieve.o sieve $(EDIR)/simple.o simple

chan.o: chan.c
	gcc -c chan.c -pthread -o chan.o

simple: chan.o $(EDIR)/simple.o
	gcc -g chan.o $(EDIR)/simple.o -pthread -o simple

$(EDIR)/simple.o: $(EDIR)/simple.c
	gcc -c $(EDIR)/simple.c -pthread -o $(EDIR)/simple.o

sieve: chan.o $(EDIR)/sieve.o
	gcc -g chan.o $(EDIR)/sieve.o -pthread -o sieve

$(EDIR)/sieve.o: $(EDIR)/sieve.c
	gcc -c $(EDIR)/sieve.c -pthread -o $(EDIR)/sieve.o

clean:
	rm $(EDIR)/*.o *.o simple sieve
