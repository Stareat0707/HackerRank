# Common Child

A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either the D or C from both strings. Note that we will not consider ABCD as a common child because we can't rearrange characters and ABCD $\neq$ ABDC.

## Function Description

Complete the commonChild function in the editor below. It should return the longest string which is a common child of the input strings.

commonChild has the following parameter(s):

* s1, s2: two equal length strings

## Input Format

There is one line with two space-separated strings, $s1$ and $s2$.

## Constraints

* $1 \leq |s1|, |s2| \leq 5000$
* All characters are upper case in the range ascii[A-Z].

## Output Format



## Sample Input 0

```text

```

## Sample Output 0

```text

```

## Explanation 0



## Sample Input 1

```text

```

## Sample Output 1

```text

```

## Explanation 1



## Solution

