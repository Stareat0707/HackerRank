# Max Min

You will be given a list of integers, $arr$, and a single integer $k$. You must create an array of length $k$ from elements of $arr$ such that its unfairness is minimized. Call that array $subarr$. Unfairness of an array is calculated as

$$max(subarr) - min(subarr)$$

Where:\
\- max denotes the largest integer in $subarr$.\
\- min denotes the smallest integer in $subarr$.

As an example, consider the array $[1, 4, 7, 2]$ with a $k$ of $2$. Pick any two elements, test $subarr[4, 7]$.\
$unfairness = max(4, 7) - min(4, 7) = 7 - 4 = 3$\
Testing for all pairs, the solution $[1, 2]$ provides the minimum unfairness.

**Note**: Integers in $arr$ may not be unique.

## Function Description

Complete the maxMin function in the editor below. It must return an integer that denotes the minimum possible value of unfairness.

maxMin has the following parameter(s):

* k: an integer, the number of elements in the array to create
* arr: an array of integers.

## Input Format

The first line contains an integer $n$, the number of elements in array $arr$.\
The second line contains an integer $k$.\
Each of the next $n$ lines contains an integer $arr[i]$ where $0 ≤ i < n$.

## Constraints

* $2 ≤ n ≤ 10^5$
* $2 ≤ k ≤ n$
* $0 ≤ arr[i] ≤ 10^9$

## Output Format

An integer that denotes the minimum possible value of unfairness.

## Sample Input 0

```text
7
3
10
100
300
200
1000
20
30
```

## Sample Output 0

```text
20
```

## Explanation 0

Here k = 3; selecting the 3 integers 10, 20, 30, unfairness equals

```text
max(10, 20, 30) - min(10, 20, 30) = 30 - 10 = 20
```

## Sample Input 1

```text
10
4
1
2
3
4
10
20
30
40
100
200
```

## Sample Output 1

```text
3
```

## Explanation 1

Here $k = 4$; selecting the $4$ integers $1, 2, 3, 4$, unfairness equals

```text
max(1, 2, 3, 4) - min(1, 2, 3, 4) = 4 - 1 = 3
```

## Sample Input 2

```text
5
2
1
2
1
2
1
```

## Sample Output 2

```text
0
```

## Explanation 2

Here $k = 2$. $subarr = [2, 2]$ or $subarr[1, 1]$ give the minimum unfairness of $0$.

## Solution

Sort $arr$ and use $max = arr[i + k - 1]$ and $min = arr[i]$ to find the minimum value.

```python
def maxMin(k, arr):
    arr.sort()

    min = arr[k - 1] - arr[0]
    for i in range(1, len(arr) - k + 1):
        if arr[i + k - 1] - arr[i] < min:
            min = arr[i + k - 1] - arr[i]

            if min == 0:
                break

    return min
```