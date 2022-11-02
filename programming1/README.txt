Jack Heineking 811178900
nov 1 2022
programming assignment 1

HOW TO USE
compile both files. 
every time you execute producer, it produces one thing.
overy time you execute consumer, it consumes one thing.
both programs have the capability to be run concurrently, as they constantly check shared memory to enforce mutual exclusion.

DOCUMENTATION
The program is written in c++. it was stated that we could do this, though it seemed like C was the preferred option
the longer I worked on it.
I was most confused about how these were meant to work concurrently. There was very little documentation on this. while it was
not stated that they must on the word document or the slides, so based off of other examples online they can be executed 
individually or concurrently, as they DO have mutual exclusion and shared memory. while tutorials for shared memory were provided,
tutorials for concurrent running were not. 
the program itself runs by having a formatted table that it reads and writes to, set to be empty first. these variables are 
manipulated by the program, and keep track of multex as well as how many items are in the file. 

EXAMPLE
the table included, shared-memory.txt starts out as empty and will report as such. you can add 2 items to it, at which point it will be full.

[jheineki@wasp operSys]$ ./consumer &./producer 
[1] 1241276
Consumer consumes 
item 0

Producer produces 
item 2
[1]+  Done                    ./consumer
[jheineki@wasp operSys]$ ./consumer &./producer 
[1] 1241513
table is full!
[jheineki@wasp operSys]$ Consumer consumes 
item 1

[1]+  Done                    ./consumer
[jheineki@wasp operSys]$ ./consumer & ./producer 
[1] 1241604
Consumer consumes 

item 0
Producer produces 
item 2
[1]+  Done                    ./consumer
[jheineki@wasp operSys]$ ./consumer & ./producer 
[1] 1241703
table is full!
[jheineki@wasp operSys]$ Consumer consumes 
item 1

[1]+  Done                    ./consumer
[jheineki@wasp operSys]$ ./consumer & ./producer 
[1] 1241817

Producer produces 
item 2
Consumer consumes 
item 0
[jheineki@wasp operSys]$ ./consumer & ./producer 
[1]+  Done                    ./consumer
[1] 1241852
table is empty!

Producer produces 
item 1
[1]+  Done                    ./consumer
[jheineki@wasp operSys]$ ./consumer & ./producer 
[1] 1242100
Consumer consumes 
item 0

Producer produces 
item 2
[1]+  Done 



many of the instructions for this seemed hard to follow, so for any questions please contact me at jheineki@kent.edu

