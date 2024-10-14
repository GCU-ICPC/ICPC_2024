### The bridge-cross planning problem

Let $G=\{u_1,\ldots,u_n\}$ be a group of people who plan to corss a bridge at night. But, at most two people are allowed to cross the bridge at any time. During any person in a group $G$ cross the bridge at night, they must have a flashlight. Unfortunately, only a single flashlight is given to the group of $n$ people. Therefore, if a good shuttle scheduling  is used to return the flashlight, then more people can cross. 

Each person has a different crossing speed; this means that the speed of a group is determined by the speed of the slower member. Thus, the main task is to develop an algorithm that gets all $n$ people across the bridge within the minimum time.

#### Input

The input begins with a single positive integer on a line by itself, representing the total number of test cases; then a blank line follows. There is also a blank line between each two consecutive test cases. The 1-st line of each test case contains $n$, followed by $n$ lines which provide the crossing times for each memebr of the group. For simplicity, assume that $n\leq 1,000$ people and no one takes more than 100 seconds to cross the bridge. 

#### Output

For each input test case, the 1st line of output should report the total number of seconds needed for all $n$ people to cross the bridge. Sesequent lines present a plan for achieving this time. Specifically, each line contains either one or two integers, indicating which person or people form the next group to cross. Each person is identified by the crossing time given in the input. Recall that each person has a distinct speed. You should note that the crossings alternate directions,  which is required to return the flashlight so that more perople may cross the bridge. If there are more than one crossing plans such that incur the minimum time, any one can be accepted.

For two or more cases, its output should be separated by a blank line.

#### Sample

__input__

```
1

4
1
2
5
10
```

__output__

```
17
1 2
1
5 10
2
1 2
```
