## Meeting April 11th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  We revisited the function spawning syntax from last week, which is now almost complete
    with a single remaining error before it will compile. 
2.  We went over concrete syntax in Go versus our extension for channel arrows, and ran a demo
    at play.golang.org demonstrating the double-arrow syntax for a recieve into a send
    operation. Eric mentioned he would look into the concrete syntax we had written to see if
    there was something we could do differently, so we didn't need to wrap recieves in parens.
3.  Briefly went over some things planned for the Summer, including revamping errors in Parse
    statements so they get translated at grammar-compiliation time instead of at jar runtime,
    and partial compilation of grammars to reduce silver compilation time.
4.  We looked through some examples of channel usage in Go from Patrick's game library, that 
    might be sufficiently interesting to demonstrate
