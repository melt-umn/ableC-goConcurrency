## Meeting March 28th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  Main topic of meeting was to discuss the progress on the abstract syntax for spawn.
    Most of the syntax was adapted from the closure extension.  There is the main production,
    and the productions for building the struct, adding values to the struct, and the final
    call to the actual function.
2.  It was decided that the names of the elements of the struct (the arguments) should simply
    increment by one up until count.  This way, all we need to pass around are the typereps
    and the length of the struct.
3.  The distinction between abstract productions and functions was cleared up.  Since most of
    our productions don't depend on any part of the inherited ast, just using the arguments
    passed in, we should use functions that will return the expressions that we need, rather
    than productions.
4.  The use of the propogate keyword was explained.  Serves as a shortcut to copy attributes
    into the top.
5.  A couple minor bugs were quickly changed in the google doc.

[Google Doc with abstract syntax](https://docs.google.com/a/umn.edu/document/d/1Thd-eBQnioeifas_a3ihKbuFbpCFo69OsshxZvklDDY/edit?usp=sharing_eil&ts=58e2bc2a)