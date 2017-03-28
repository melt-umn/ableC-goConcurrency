## Meeting March 28th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1.  Discussed issues including templated header files. Patrick and Will ended up dumping the templated code into one file
    to get something working prior to this. Erik suggested that, using templates, the header file would need to include 
    function bodies, but would otherwise work as expected if included in the .xc file. Erik requested that, once we look
    into this and (hopefully) get this working Lucas should be emailed (Erik cc'd) as to if this is the intended approach
    
2.  Otherwise demonstrated templated channels working, discussed whether or not the syntax we were using was significantly
    justifiable considering the templating extension builds so much of it for us. Concluded that it was a little beneficial 
    to have the send/receive syntax, and the close syntax, to avoid the type tags.
    
3.  Planned on demonstrating templating working with the go-concurrency extension this Thursday the 30th. 
