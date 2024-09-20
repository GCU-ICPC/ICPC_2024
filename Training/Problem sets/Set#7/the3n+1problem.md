### The $3n+1$ problem



This problem was introdcued by J. Lagarias at the paper, entitled "The $3x+1$ problem and its generalizations" at American mathematical monthly, 92:3-23, 1985.  Later, an international conference on the Collatz problem presented its variants: please visit the [site](https://chamberland.math.grinnell.edu/conference/proceedings.html) for downloading documents on them.



#### Introduction to the problem

Consider the following algorithm to generate a sequence of numbers

- Start with an integer $n$
- If $n$ is even, then divide by 2; else multiply by 3 and add 1
- Repeat the process with the new value of $n$, terminating when $n=1$

For example, a sequence for $n=22$ is computed as followings

$22\mapsto 11\mapsto 34\mapsto 17\mapsto 52\mapsto 26\mapsto 13\mapsto 40\mapsto 20\mapsto 10\mapsto 5\mapsto 16\mapsto 8\mapsto 4\mapsto 2\mapsto 1$

Unfortunately, it is not yet proven, but is conjectured that this process will terminate at $n=1$ for every integer $n$. Fortunately, the conjecture is valid for all integers $\leq 1,000,000$. 



__Def. (Cycle length)__ 

For an input $n$, the cycle length of $n$ is the number of integers generated up to and including 1. Furthermore, given any two integers $n$ and $m$, you are to determine the maximum cycle length over all numbers between $n$ and $m$, including those end points.



__Example__

In the example above, the cycle length of 22 is 16.



__Input__

The input consists of a series of pairs of integers $n$ and $m$, one pair of integers per line. In particular, all integers are positive and $\leq 10^6$ due to the conjecture as above discussed.

__Output__

For each pair of input integers $n$ and $m$, output $n,m$ in the same order as in the input and then the maximum cycle length for integers between and including $n$ and $m$. Those three values should be separated by a single space, with all three numbers on one line and with one line of output for each line of input.

__Sample input/output__

```
1 10					1 10 20
100 200					100 200 125
201 210					201 210 89
900 1000				900 1000 174
```



#### Hints

To my experience,  no easy ways to solve this problem. Just use loop and calculations; however, you may have some tricks to save loop iterations by paying attention to even and odd computation.
