# Triple sum

Given $3$ arrays $a, b, c$ of different sizes, find the number of distinct triplets $(p, q, r)$ where $p$ is an element of $a$, written as $p ∈ a$, $q ∈ b$, and $r ∈ c$, satisfying the criteria: $p ≤ q\ and\ q ≥ r$.

For example, given $a = [3, 5, 7], b = [3, 6],$ and $c = [4, 6, 9]$, we find four distinct triplets: $(3, 6, 4), (3, 6, 6), (5, 6, 4), (5, 6, 6)$.

## Function Description

Complete the triplets function in the editor below. It must return the number of distinct triplets that can be formed from the given arrays.

triplets has the following parameter(s):

* a, b, c: three arrays of integers.

## Input Format

The first line contains $3$ integers $lena, lenb,\ and\ lenc$, the sizes of the three arrays.\
The next $3$ lines contain space-separated integers numbering $lena, lenb,\ and\ lenc$ respectively.

## Constraints

$1 ≤ lena, lenb, lenc ≤ 10^5$

$1 ≤ all\ elements\ in\ a, b, c ≤ 10^8$

## Output Format

Print an integer representing the number of distinct triplets.

## Sample Input 0

```text
3 2 3
1 3 5
2 3
1 2 3
```

## Sample Output 0

```text
8
```

## Explanation 0

The special triplets are $(1,2,1),(1,2,2),(1,3,1),(1,3,2),(1,3,3),(3,3,1),(3,3,2),(3,3,3)$.

## Sample Input 1

```text
3 3 3
1 4 5
2 3 3
1 2 3
```

## Sample Output 1

```text
5
```

## Explanation 1

The special triplets are $(1,2,1),(1,2,2),(1,3,1),(1,3,2),(1,3,3)$.

## Sample Input 2

```text
4 3 4
1 3 5 7
5 7 9
7 9 11 13
```

## Sample Output 2

```text
12
```

## Explanation 2

The special triplets are $(1,7,7),(1,9,7),(1,9,9),(3,7,7),(3,9,7),(3,9,9),(5,7,7),(5,9,7),(5,9,9),(7,7,7),(7,9,7),(7,9,9)$.

## Solution

1. Sort $a,b,c$ and delete duplicate.
2. Sequentially traverse $b$ and find $a[j], b[k]$ less than $b[i]$ and update $j, k$.
3. Add $j × k$ to the result.
4. Repeat the above procedure.