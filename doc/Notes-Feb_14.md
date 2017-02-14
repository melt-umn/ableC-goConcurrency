## Meeting February 14th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  Went through the built functions for send and recieve with the example.  Currently have issues with
    pointers to local variables.  Currently working around with sleep(1), but the value should really be
    copied to make it robust.  Should expand the main function to really stress test the functions.

2.  Remake the functions required for select to work.  Were removed to get the example to work properly,
    but should be need to be added back in.  Build test cases to ensure it works properly.  Lay out explicitly
    what our xc code will expand into.
    
3.  Build examples and prepare to present something to the group on Thursday.  Disscussed the possibility
    of writing a parallel program to calculate primes.  May go through chan.c code, examples, and visual
    aid drawn on whiteboard.
    
4.  Discussed the plan for chan_close.  Considered whether we will implement a boolean for closed, or if
    the memory should just be cleared.