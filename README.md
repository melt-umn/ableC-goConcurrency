## Go Concurrency for C
This extension will allow for concurrency similar to that found in the language go
into ableC for use in C programs.  Concurrent goroutines can be called from functions.
It will also allow for the creation of the channel data type in order to pass data
to and from this concurrent processes.

### Creating Channels
Data is passed back and forth between concurrent functions using channels, exactly as
it is in go.  Channels are defined using the new keyword `chan` as
```
chan int ch = open chan;
```
for an integer channel.  Multiple channels are defined similarly as
```
chan int ch1 = open chan;
chan int ch2 = open chan;
chan int ch3 = open chan;
```
Channels can be passed into functions like any other data type.
```
int printTwice (chan int ch2) {}
```
The operator `<-` is used to pass data into a channel or to read from one.
```
int foo;
ch1 <- 4;
foo <- ch2;
```
### Spawing Concurrent Functions
We call functions to run concurrently using the keyword `spawn`.  These concurrent calls
work similarly to the goroutines in go and `spawn` is analogous to go's `go` keyword.
`spawn` works for calling defined functions:
```
int main (int argc, char **argv) {
  chan int ch = open chan;
  spawn example(ch);
  <-ch;
  return 0; 
}

int example (chan int ch2) {
  ch2 <- 1;
  return 0;
}
```
It can also be used on closures:
```
int main (int argc, char **argv) {
  chan int ch = open chan;
  spawn func(chan int ch2) {
    ch2 <- 1;
  }(ch);

  <-ch;
  return 0; 
}
```
In both of these cases `<-ch' is used so `main()` waits for the concurrent
function to push some data to the channel before returning.  Without this,
`main` would return and end execution before the concurrent functions are
able to do anything.

For more examples see the `examples` directory.

## Status
Just a skeleton right now.  Positive and negative examples show usage, but
nothing is functioning.


