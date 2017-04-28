## Meeting April 18th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  We started by taking a look at the work done on spawning.  It is mostly complete and
    has a working example.  A wrapper function and struct are made to wrap up the args
    before unwrapping.
2.  Eric discusses additional checking for errors throughout the project.  We currently
    check if something is a channel by looking if it is a struct with component "v".
    Most of the error checking throughout the grammar is currently being handled by 
    C type checking, but this could be improved.
3.  Eric suggests that we begin to look at modular analysis.  Add --warn -all to the build
    script.  We can take a look at this in the upcoming meeting on Thursday.
4.  Also in the meeting on Thursday, we will discuss splitting an extension up into
    multiple grammars.  This is mostly determined by the marking terminals, but Eric
    will give additional suggestions.
5.  Plans to add the select statement.  We will start by adding a simple busy-wait loop.
    It would be good to have an extension that is "done" by the end of the semester.
    This shouldn't be too hard to add.
6.  Eric and Patrick discussed plans for the summer and the fall semester.
