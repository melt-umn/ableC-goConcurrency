## Meeting March 21th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  Discussed the work done on the wrapper function.  Looked at concrete syntax for the spawning.
    Much of the work will be done similar to the closure extension.  Abstract syntax not yet written.

2.  Talked about concerns with the generation of names.  Agreement that there should be a robust
    universal method for this.  The closure extension uses the name 'env' with no checking.
    There should be an easy way for the compiler to recognize name collisions and change them to
    a longer name if necessary.  Some extensions use genInt(), which we thought just generated
    a random number but actually is supposed to generate a new number each time.  Still could cause
    a collision with a user written name.
    
3.  Talked about the future with templating.  Lucas plans to explain the changes and improvements
    that he has made in upcoming Thursday meeting.  This will hopefully allow for easier building
    of channel structs.  Currently there are just everything is a void*, but this will make it 
    easier to have a different channel type for each data type the user wants to use.

4.  Talked about select statements.  In previous Thursday meeting, Lucas suggested that the colon
    syntax found in the standard C switch statement not be used.  We plan to try the colon sytax
    and see if it causes any problems.  It can always be changed if is causing problems.