### Palindrome number problem

The palindrome number problem is defined as follows:
Let $N$ be a positive integer. The problem requires to find all integers less than or equal to $N$ where $N$ is assumed to be less than `INT_MAX` in `limits.h` in C++. 

A solution is given as a C++ code whose main idea is:

- Let $n\leq N$ be a positive integer which is written as $d_1d_2\cdots d_{n-1}d_n$. 
- In order to extract $d_1$, do $\lfloor{n/10^{n-i}}\rfloor\pmod{10}$ and for $d_n$, do $\lfloor(n\pmod{10^i})/10^{i-1}\rfloor$.
