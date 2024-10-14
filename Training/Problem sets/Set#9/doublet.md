### The doublet problem

**Def.** (Doublet) 

A doublet is a pair of words that differ in extactly one letter. For example, consider the following: ("booster", "rooster"), ("rooster", "roaster"), and ("roaster", "roasted").

In this problem, you will be given a list of lowercase words less than 25,143 and each of words does not exceed 16 letters. In addition, you are given a number of pairs of words. Now you mission is that for each of pairs, find the shortest sequence of words that begins with the 1st word and ends with the the 2nd, such that each pair of adjacent words is a doublet. For example, if you were given the input pair ("booster", "roasted"), a possible solution would be 

("booster","rooster","roaster","roasted"),

if all of these words are present in the input list of words. 



#### Input

As mentioned above, the input contains a list of words, followed by a number of word pairs. The list consists of a number of words, one per line, and is terminated by a blank line. The pairs of input words follow; each pair of words occurs on a line separated by a single space.



#### Output

For each input pair, print a sequence of lines starting with the the 1st word and ending with the last so that each pair of adjacent lines must be a doublet. If there are several minimal solutions, any one will do. If there is no solution, print a line: "no solution." Print a blank line between cases.



#### Sample

__input__

```
booster
rooster
roaster
coasted
roasted
coasral
postal

booster roasted
coastal postal
```

__output__

```
booster
rooster
roaster
roasted

no solution.
```
