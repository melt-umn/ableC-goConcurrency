EDIR = ./examples

all: chan.o $(EDIR)/sieve.o sieve $(EDIR)/simple.o simple $(EDIR)/overload.o overload $(EDIR)/select.o select

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

overload: chan.o $(EDIR)/overload.o
	gcc -g chan.o $(EDIR)/overload.o -pthread -o overload

$(EDIR)/overload.o: $(EDIR)/overload.c
	gcc -c $(EDIR)/overload.c -pthread -o $(EDIR)/overload.o

select: chan.o $(EDIR)/select.o
	gcc -g chan.o $(EDIR)/select.o -pthread -o select

$(EDIR)/select.o: $(EDIR)/select.c
	gcc -c $(EDIR)/select.c -pthread -o $(EDIR)/select.o

clean:
	rm $(EDIR)/*.o *.o simple sieve overload select
