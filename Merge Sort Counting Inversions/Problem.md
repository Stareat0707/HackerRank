# Merge Sort: Counting Inversions

Check out the resources on the page's right side to learn more about merge sort. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book [Cracking the Coding Interview](https://www.hackerrank.com/ctci-book?ref=body).

In an array, $arr$, the elements at indices $i$ and $j$ (where $i < j$) form an inversion if $arr[i] > arr[j]$. In other words, inverted elements $arr[i]$ and $arr[j]$ are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

For example, consider the dataset $arr = [2, 4, 1]$. It has two inversions: $(4, 1)$ and $(2, 1)$. To sort the array, we must perform the following two swaps to correct the inversions:

$$arr = [2, 4, 1]\xrightarrow{swap(arr[1], arr[2])\to swap(arr[0], arr[1])}[1, 2, 4]$$

Given $d$ datasets, print the number of inversions that must be swapped to sort each dataset on a new line.

**Function Description**

Complete the function countInversions in the editor below. It must return an integer representing the number of inversions required to sort the array.

countInversions has the following parameter(s):

- arr: an array of integers to sort.

**Input Format**

The first line contains an integer, $d$, the number of datasets.

Each of the next $d$ pairs of lines is as follows:

1. The first line contains an integer, $n$, the number of elements in $arr$.
2. The second line contains $n$ space-separated integers, $arr[i]$.

**Constraints**

- $1 \leq d \leq 15$
- $1 \leq n \leq 10^5$
- $1 \leq arr[i] \leq 10^7$

**Output Format**

For each of the $d$ datasets, return the number of inversions that must be swapped to sort the dataset.

**Sample Input**

```
2
5
1 1 1 2 2
5
2 1 3 1 2
```

**Sample Output**

```
0
4
```

**Explanation**

We sort the following $d = 2$ datasets:

1. $arr = [1, 1, 1, 2, 2]$ is already sorted, so there are no inversions for us to correct. Thus, we print  on a new line.
2. $arr = [2, 1, 3, 1, 2] \xrightarrow{1 swap} [1, 2, 3, 1, 2] \xrightarrow{2 swaps} [1, 1, 2, 3, 2] \xrightarrow{1 swap} [1, 1, 2, 2, 3]$

We performed a total of $1 + 2 + 1 = 4$ swaps to correct inversions.

# 병합 정렬: 역수 계산

병합 정렬에 대한 자세한 내용은 페이지의 오른쪽에 있는 리소스를 확인하십시오. 비디오 자습서는 Gayle Laakmann McDowell의 베스트셀러 인터뷰 책인 [Coding Interview](https://www.hackerrank.com/ctci-book?ref=body)의 저자입니다.

$arr$ 배열의 경우, $i$와 $j$의 인덱스 ($i < j$)의 요소는 $arr[i] > arr[j]$의 경우에 반전을 형성합니다. 즉, 반전된 요소 $arr[i]$와 $arr[j]$는 "순서가 맞지 않는"것으로 간주됩니다. 역변환을 수정하기 위해 인접한 요소를 바꿀 수 있습니다.

예를 들어, $arr = [2, 4, 1]$ 데이터 집합을 생각해보십시오. 그것은 $(4, 1)$과 $(2, 1)$의 두 가지 반전이 있습니다. 배열을 정렬하려면 다음 2 가지 스왑을 수행하여 역변환을 수정해야합니다.

$$arr = [2, 4, 1]\xrightarrow{swap(arr[1], arr[2])\to swap(arr[0], arr[1])}[1, 2, 4]$$

$d$개의 데이터 세트를 준다면, 새로운 라인에서 각 데이터 세트를 정렬하기 위해 교체해야 하는 역전의 수를 출력하십시오.

**함수 설명**

아래 편집기에서 함수 countInversions를 완성하십시오. 배열을 정렬하는 데 필요한 역전 수를 나타내는 정수를 반환해야 합니다.

countInversions에는 다음 매개 변수가 있습니다.

- arr: 정렬할 정수의 배열.

**입력 형식**

첫 번째 줄에는 데이터 집합의 수인 정수 $d$가 들어 있습니다.

다음 $d$쌍의 줄 각각은 다음과 같습니다.

1. 첫 번째 행에는 $arr$에 있는 요소의 수인 정수 $n$이 포함됩니다.
2. 두 번째 줄에는 $n$개의 공백으로 구분된 정수 $arr[i]$가 있습니다.

**제약 조건**

- $1 \leq d \leq 15$
- $1 \leq n \leq 10^5$
- $1 \leq arr[i] \leq 10^7$

**출력 형식**

n개의 데이터 세트 각각에 대해 데이터 세트를 정렬하기 위해 교체해야 하는 역전의 수를 반환합니다.

**샘플 입력**

```
2
5
1 1 1 2 2
5
2 1 3 1 2
```

**샘플 출력**

```
0
4
```

**설명**

우리는 다음 $d = 2$가지 데이터 세트를 정렬합니다.

1. $arr = [1, 1, 1, 2, 2]$은 이미 정렬되어 있으므로 수정할 필요가 없습니다. 따라서 새로운 줄에 인쇄합니다.
2. $arr = [2, 1, 3, 1, 2] \xrightarrow{1 swap} [1, 2, 3, 1, 2] \xrightarrow{2 swaps} [1, 1, 2, 3, 2] \xrightarrow{1 swap} [1, 1, 2, 2, 3]$

우리는 역전을 바로 잡기 위해 총 $1 + 2 + 1 = 4$회의 교환을 수행했습니다.

# 해결법

합병 정렬을 이용하면 배열의 역수의 개수를 쉽게 구할 수 있다.

정렬 중 두 값의 순서가 뒤바뀔 때마다 역수의 개수를 더해주면 된다.