### Palindrome number problem

The palindrome number problem is defined as follows:
Let $N$ be a positive integer. The problem requires to find all integers less than or equal to $N$ where $N$ is assumed to be less than `INT_MAX` in `limits.h` in C++. 

A solution is given as a C++ code whose main idea is:

- Let $n\leq N$ be a positive integer which is written as $d_1d_2\cdots d_{n-1}d_n$. 
- In order to extract $d_1$, do $\lfloor{n/10^{n-i}}\rfloor\pmod{10}$ and for $d_n$, do $\lfloor(n\pmod{10^i})/10^{i-1}\rfloor$.

The main objective is to check the possibility to make a code without relying on any data structure.
Unfortunately, I did not check whether this approach could be better than any other approach (e.g., stack-based approach and string conversion-based approach etc). Therefore, use it as a reference code.
