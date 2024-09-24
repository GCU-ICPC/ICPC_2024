### The word locating problem

The goal of this problem is that given an $m\times n$ lattice of English letters and a list of English words, find the location in the lattice at which the word can be found.

A word matches a straight, contiguous line of letters in the lattice. A word can match the letters in the lattice regardless of case (i.e., upper case and lowcase letters are considered as the same). The matching can be found in any of the 8 horizontal, vertical, and diagonal directions through the lattice.



#### Input

The input begins with a positive integer $t(1\leq t\leq 10)$ on a line that indicates the number of cases you need to handle with. Skipping one blank line, If two or more cases are given, there is also a blank line between each of two consecutive cases. 

Each case begins with a pair of poitive integers $m,n$ on a single line, but $m,n\in\{1,2,\ldots,50\}$ and  these two values are separated by a single space. Each of the next $m$ lines consists of $n$ letters, representing the lattice of letters where the word must be compared against. The letter in the lattice may be in uppercase or lowercase however, as mentioned above you do not need to care the case. Following the lattice of letters, another posive integer $k\in\{1,2,\ldots,20\}$ appears on a line by itself. Thus, the next $k$ lines contains of $k$ words to search for, one word per line. These $k$ words also may have uppercase and lowercase letters, but special letters including the blank and numeric letters are not allowed. 

#### Output

For each word (i.e., $k$ words) in each test case (you have $t$ cases), output a pair $(\delta_x,\delta_y)$ of integers, representing its location of  in the corresponding lattice. The integers in the pair should be written and separated by one space. More specifically, the first integer $\delta_x$ is the line in the lattice where the first letter of the given word (e.g., `a` for a given word `acid`) can be found; thus $1$ indicates the topmost line in the lattice and $m$ indicates the bottommost line. The second integer $\delta_y$ the column in the lattice where the first letter of the given word can be found; similarly, thus $1$ indicates the leftmost column and $n$ indicates the rightmost column in the lattice. If a given word can be found one or more locations in the lattice, then output the location of the uppermost occurrence of the word; that is, the occurrence whose first letter is located closest to the top of the lattice. If two or more words are uppermost, then output the leftmost of these occurrences. All words can be found at least once in the lattice. 

For two or more cases, its output should be separated by a blank line.

#### Sample

__input__

```
1

8 11
abcDefGhigg
HEbKwaLDOrk
fTyAwaldoRM
FtsimrlQsRC
bYoArBEDeyV
klCBqwikOmK
StRebGadhrb
yUIQlxcnBjF
3
Bambi
Betty
Dagbert
```

__output__

```
2 3
1 2
7 8
```
