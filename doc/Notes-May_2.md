## Meeting May 2nd 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  Discussed final plans.  End of the semester is this week, so we must finish up and have
    something to show at Thursday meeting.  All that's left is fixing up errors.
    
2.  Problems with the <- operator for sending.  Not being interpreted correctly by compiler.
    Eric suggests using it as an assignment operator.  It could be overloaded and used interpreted
    this way rather than as just a marking terminal like it is now.

3.  To go along with the new use for sending, recieving could use <- as a unary operator
    Similar to ++ or --, the operator would act on the expresion and then return an expression.
    This would allow it to be used with or without a variable to push the value to.
