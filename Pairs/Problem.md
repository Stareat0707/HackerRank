# Pairs

You will be given an array of integers and a target value. Determine the number of pairs of array elements that have a difference equal to a target value.

For example, given an array of [1, 2, 3, 4] and a target value of 1, we have three values meeting the condition: $2 - 1 = 1$, $3 - 2 = 1$, and $4 - 3 = 1$.

## Function Description

Complete the pairs function below. It must return an integer representing the number of element pairs having the required difference.

pairs has the following parameter(s):

* k: an integer, the target difference
* arr: an array of integers

## Input Format

The first line contains two space-separated integers $n$ and $k$, the size of $arr$ and the target value.\
The second line contains $n$ space-separated integers of the array $arr$.

## Constraints

* $2 ≤ n ≤ 10^5$
* $0 < k < 10^9$
* $0 < arr[i] < 2^{31} - 1$
* each integer $arr[i]$ will be unique

## Output Format

An integer representing the number of pairs of integers whose difference is $k$.

## Sample Input

```text
5 2
1 5 3 4 2
```

## Sample Output

```text
3
```

## Explanation

There are 3 pairs of integers in the set with a difference of 2: [5, 3], [4, 2] and [3, 1].

## Solution

Save in map and search sequentially.

```python
def pairs(k, arr):
    dic = dict()

    for i in arr:
        dic[i] = True

    count = 0
    for key, value in dic.items():
        if dic.get(key + k):
            count += 1

    return count
```