## Meeting April 25th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  We discussed ongoing work on the select statement code. Eric proposed some revisions, recommending that
    we parse through and construct our syntax tree on each case as each case is constructed, wrapping in a 
    'SelectCases' type, where the default case would be specially stored in the SelectCases. Mentioned that
    it would probably be okay to use 'case' instead of making a new case terminal. 
