### Political strikes

Political parties in some countries like India and Bangladesh show thier forcibility and muscle by calling for regular strikes (called _Hartals_) since such political strikes cause significant economic damage. 



#### Introduction to the problem

In this problem, each political party is denoted by $P_i$ and parameterised by a hartal parameter $h_i$ of $P_i$. 

__Def. (Hartal parameter)__

The hartal parameter, which is a positive integer, denotes the average number of days between two successive strikes.

__Example__

 Let $P_1,P_2$, and $P_3$ be political parties and $h_i$ be their hartal parameter, ane let $N$ be a period of days. Assume that $h_1=3,h_2=4,h_3=8$ and $N=14$. The following table is a simulation of three parties during two weeks, i.e., $N=14$. For this purpose, we always start the simulation on a Sunday and assume that no strikes are allowed on either Fridays or Saturdays. See the below:

```
		1   2   3   4   5   6   7   8   9   10  11  12  13  14     
Days            Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa
Party 1         x           x           x           x
Party 2             x               x               x 
Party 3                             x
Strikes         1   2               3   4           5
```

There will be exactly 5 strikes on days 3, 4, 8, 9, 12 over 14 days. Note that there is no stike on day 6 because it falls on Friday. Therefore, we lose five working days in two weeks.



__Input__

The first line of the input consists of a single integer $T$ denoting the number of test cases to follow. The first line of each test case contains an integer $N (7\leq N\leq 3,650)$, denoting the number of days over which the simulation should be run. The next line contains another integer $P(1\leq P\leq 100$ representing the number of political parties. The $i$-th of the next $P$ lines contains a positive integer $h_i$ (which will be never be a multiple of 7) representing the hartal parameter for party $P_i(1\leq i\leq P)$.  

__Output__

Given the hartal parameter for several potical parties and the integer $N$, determine the number of working days lost in those $N$ days. More specifically, for each test case, output the number of working days lost on a separate line.

__Sample input__

```
2
14
3
3
4
8
100
4
12
15
25
40
```

__Sample output__

```
5
15
```



#### Hints

To my experience, a proper data structure is useful and helpful; however, a first step may be to build a table to compute the number of strikes.









   
