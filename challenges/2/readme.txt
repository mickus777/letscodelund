IDA*
====

IDA* is a general purpose search algorithm which uses a heuristic to speed up
the search.

See https://en.wikipedia.org/wiki/Iterative_deepening_A* for an introduction. 


Challenge:
----------

Write an implementation of IDA* and use it to solve the 15 puzzle:

https://en.wikipedia.org/wiki/15_puzzle

Your program should read in a text based representation of the puzzle and
output the number of steps needed in an optimal solution (smallest number
of steps). There are sample puzzles in the data directory (x marks the
empty spot).

Did you make any interesting design decisions?

How much does choice of heuristic affect the speed of the algorithm?


More sample puzzles:
--------------------

I've added some more puzzles to the data directory. They're named after the number of moves needed to solve them. But a smaller number does not always mean easier....  /Max