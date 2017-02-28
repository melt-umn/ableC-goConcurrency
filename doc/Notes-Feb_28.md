## Meeting February 28th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1. Went over current abstract and concrete syntax for open chan.
  * Discussed the purpose and neccesity of lexar classes and marking terminals. Marking terminals are needed to mark the beginning of an expression in the syntax.  For open chan, this would be open.  Each marking terminal needs its own grammar.
  * Discussed that declaring the type of the channel on both the left and right is neccesary if we are using c type checking.
  * Other than these problems, the syntax should be fine.
2. Discussed how type checking is accomplished.  Type statements can include type qualifiers (const, volatile) and type specifiers (int, long, etc.).  Vectors includes an analysis of this.  This will need to be added to channels in order to type check data sent and recieved on channels.
3. Looked at other examples of extensions to help get hints.
  * The vector extension showed the use of lexar classes, marking terminals.
  * Condition tables showed basic syntax by expanding into a series of boolean expressions.
4. Talked about upcoming Thursday meeting where useful topics will be discussed.  Templating extension may be useful for our extension.
5. Found source of fetch-jars error.  Nathan's recently pushed jar had missing permissions.