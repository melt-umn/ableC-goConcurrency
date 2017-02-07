## Meeting February 7th 2017

Persons Attending: Eric Van Wyk, Will Croteau, Patrick Stephen

1. Discussed the potential issues with competing parallel-computation backends. I.E. Pthreads appe0ars to 
   check locks by assigning lock ownership to threads by internal ids. Other backends may be unable
   to interact with these locks. The solution discussed was an eventual combined runtime provided by
   ableC that all implementing extensions would use to be compliant with one-another. A request was made
   for putting together examples of potential interfering backends. 

2. A paper concerning go channels and goroutines was brought up, it introduces the concept of a localized
   deadlock within some channel tree. See file: fencing_off_go.pdf. We didn't go into deep discussion on 
   the paper, but considered building in its proposals in the future.

3. The general strategy behind channels was discussed. The requirement for a lock around the 'claiming' process
   for senders or recivers to find appropriate opposites to sync with was dicussed, and questions on how best to
   perform a busy wait (or if a busy wait can be avoided through signals to the processor) were discussed. Work 
   continues but the solutions presented appear suspiciously easy (qtd Patrick). Current implementation uses
   pthreads, but discussion led to the recommendation that pthreads be one of many potential implementations 
   and work should begin this week on building header file(s) to satisfy an interface for said implementations. 

4. Discussion on the select construct. Conclusion to implement a basic, in order check, compiled to C as a 
   series of if else blocks, prior to doing anything fancier with a runtime and pseudo-random ordering.

5. Brief discussion of channel types, noting that both Go internally and pthreads internally pass information
   between threads as *void or an equivalent. A ctype.h file was provided as an example for making primitive
   supporting channels through a union, but the *void approach may be what is come to anyway.