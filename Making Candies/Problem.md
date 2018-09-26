# Making Candies

Karl loves playing games on social networking sites. His current favorite is CandyMaker, where the goal is to make candies.

Karl just started a level in which he must accumulate $n$ candies starting with $m$ machines and $w$ workers. In a single pass, he can make $m × w$ candies. After each pass, he can decide whether to spend some of his candies to buy more machines or hire more workers. Buying a machine or hiring a worker costs $p$ units, and there is no limit to the number of machines he can own or workers he can employ.

Karl wants to minimize the number of passes to obtain the required number of candies at the end of a day. Determine that number of passes.

For example, Karl starts with $m = 1$ machine and $w = 2$ workers. The cost to purchase or hire, $p = 1$ and he needs to accumulate $60$ candies. He executes the following strategy:

1. Make $m × w = 1 × 2 = 2$ candies. Purchase two machines.
2. Make $3 × 2 = 6$ candies. Purchase $3$ machines and hire $3$ workers.
3. Make $6 × 5 = 30$ candies. Retain all $30$ candies.
4. Make $6 × 5 = 30$ candies. With yesterday's production, Karl has $60$ candies.

## Function Description



## Input Format



## Constraints



## Output Format



## Sample Input

```text

```

## Sample Output

```text

```

## Explanation



## Solution

