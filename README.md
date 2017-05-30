## Go Concurrency for C
This extension will allow for concurrency similar to that found in the language go
into ableC for use in C programs.  Concurrent goroutines can be called from functions.
It will also allow for the creation of the channel data type in order to pass data
to and from this concurrent processes.

### Creating Channels
Data is passed back and forth between concurrent functions using channels, exactly as
it is in go.  Channels are defined using the new keyword `chan` as
```
Channel<int> *ch = open_chan<int>()
```
for an integer channel.  Multiple channels are defined similarly as
```
Channel<int> *ch1 = open_chan<int>()
Channel<int> *ch2 = open_chan<int>()
Channel<int> *ch3 = open_chan<int>()
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
int example (chan int ch2) {
  ch2 <- 1;
  return 0;
}

int main (int argc, char **argv) {
  Channel<int> *ch = open chan;
  spawn example(ch);
  <-ch;
  return 0; 
}
```
In both of these cases `<-ch' is used so `main()` waits for the concurrent
function to push some data to the channel before returning.  Without this,
`main` would return and end execution before the concurrent functions are
able to do anything.

For more examples see the `examples` directory.

### Select blocks
One can make a `select` statement that waits for one of any number of channel
operations to happen, or on default proceeds on without blocking.

```
select {
  case ch <- 2:
  case v = <-ch:
  case <-ch:
  default:
}
```

Select statements are not randomized as in Go. In Go, if more than one channel
operation could happen when a select block is reached, it will pick one at random.
Our extension will always pick the first available statement in order, top-down.

## Status

Full functionality for non-buffered channels, non-closures.

MDA and MDFA pass.

Some errors could be made to be nicer strings, some 
additional error checking could be added with more
failure cases. 
 