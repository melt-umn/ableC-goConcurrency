## Meeting March 7th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1. Discussed next steps, having built productions for everything but function spawning and select statements.
   We concluded that some work should go into creating buffered channels, and plans for how select statements
   should generate code should be written up to get some advice from Lucas and Travis on how we might go about
   using the code parsing components in Silver to make code generation easier. 
 
2. Discussed making ableC tutorials and test cases for those tutorials, specifically with reference to using ableC's
   type system. We might write tutorials for things we encounter that we have initial difficulty figuring out. 
   
3. In line with getting advice from Lucas and Travis, Eric suggested that MELT meets this Thursday without him
   to go over some questions we might have about ableC, as well as to build towards making tutorials.
   
4. Discussed the Go runtime and difficulties implementing it's scheduler. Specifically, Go appears to have special
   knowledge about what function calls are network or OS calls and that knowledge is incorporated into Go's
   scheduler to avoid busy waits. We questioned how reasonable re-implementing all of this go runtime work would
   be and speculated that without doing this work, detecting thread deadlocks would be impossible. 
