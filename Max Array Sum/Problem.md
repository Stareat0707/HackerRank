# Max Array Sum

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array $arr = [-2, 1, 3, -4, 5]$ we have the following possible subsets:

```text
Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
```

Our maximum subset sum is $8$.

## Function Description

Complete the $maxSubsetSum$ function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

* arr: an array of integers

## Input Format

The first line contains an integer, $n$.\
The second line contains $n$ space-separated integers $arr[i]$.

## Constraints

* $1 ≤ n ≤ 10^5$
* $-10^4 ≤ arr[i] ≤ 10^4$

## Output Format

Return the maximum sum described in the statement.

## Sample Input 0

```text
5
3 7 4 6 5
```

## Sample Output 0

```text
13
```

## Explanation 0

Our possible subsets are $[3, 4, 5], [3, 4], [3, 6], [3, 5], [7, 6], [7, 5]$ and $[4, 5]$. The largest subset sum is $13$ from subset $[7, 6]$

## Sample Input 1

```text
5
2 1 5 8 4
```

## Sample Output 1

```text
11
```

## Explanation 1

Our subsets are $[2, 5, 4], [2, 5], [2, 8], [2, 4], [1, 8], [1, 4]$ and $[5, 4]$. The maximum subset sum is $11$ from the first subset listed.

## Sample Input 2

```text
5
3 5 -7 8 10
```

## Sample Output 2

```text
15
```

## Explanation 2

Our subsets are $[3, -7, 10], [3, -7], [3, 8], [3, 10], [5, 8], [5, 10]$ and $[-7, 10]$. The maximum subset sum is $15$ from the fifth subset listed.

## Solution

Use Dynamic Programming.