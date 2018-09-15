# Luck Balance

Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary contests. She believes in "saving luck", and wants to check her theory. Each contest is described by two integers, $L[i]$ and $T[i]$:

* $L[i]$ is the amount of luck associated with a contest. If Lena wins the contest, her luck balance will decrease by $L[i]$; if she loses it, her luck balance will increase by $L[i]$.
* $T[i]$ denotes the contest's importance rating. It's equal to $1$ if the contest is important, and it's equal to $0$ if it's unimportant.

If Lena loses no more than $k$ important contests, what is the maximum amount of luck she can have after competing in all the preliminary contests? This value may be negative.

For example, $k = 2$ and:

```text
Contest     L[i]    T[i]
1           5       1
2           1       1
3           4       0
```

If Lena loses all of the contests, her will be $5 + 1 + 4 = 10$. Since she is allowed to lose $2$ important contests, and there are only $2$ important contests. She can lose all three contests to maximize her luck at $10$. If $k = 1$, she has to win at least $1$ of the $2$ important contests. She would choose to win the lowest value important contest worth $1$. Her final luck will be $5 + 4 - 1 = 8$.

## Function Description

Complete the luckBalance function in the editor below. It should return an integer that represents the maximum luck balance achievable.

luckBalance has the following parameter(s):

* k: the number of important contests Lena can lose
* contests: a 2D array of integers where each $contests[i]$ contains two integers that represent the luck balance and importance of the $i^{th}$ contest.

## Input Format

The first line contains two space-separated integers $n$ and $k$, the number of preliminary contests and the maximum number of important contests Lena can lose.\
Each of the next $n$ lines contains two space-separated integers, $L[i]$ and $T[i]$, the contest's luck balance and its importance rating.

## Constraints

* $1 \leq n \leq 100$
* $0 \leq k \leq N$
* $1 \leq L[i] \leq 10^4$
* $T[i] \in \{0, 1\}$

## Output Format

Print a single integer denoting the maximum amount of luck Lena can have after all the contests.

## Sample Input

```text
6 3
5 1
2 1
1 1
8 1
10 0
5 0
```

## Sample Output

```text
29
```

## Explanation

There are $n = 6$ contests. Of these contests, $4$ are important and she cannot lose more than $k = 3$ of them. Lena maximizes her luck if she wins the $3^{rd}$ important contest (where $L[i] = 1$) and loses all of the other five contests for a total luck balance of $5 + 2 + 8 + 10 + 5 - 1 = 29$.

## Solution

Sort in order of $L[i]$ and calculate luck.

```python
def luckBalance(k, contests):
    contests.sort(key = lambda contest: contest[0], reverse = True)

    luck = 0
    for i in range(0, len(contests)):
        if contests[i][1] == 0 or k > 0:
            luck += contests[i][0]

            if contests[i][1] == 1:
                k -= 1
        else:
            luck -= contests[i][0]

    return luck
```