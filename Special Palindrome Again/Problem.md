# Special Palindrome Again

A string is said to be a special palindromic string if either of two conditions is met:

- All of the characters are the same, e.g. aaa.
- All characters except the middle one are the same, e.g. aadaa.

A special palindromic substring is any substring of a string which meets one of those criteria. Given a string, determine how many special palindromic substrings can be formed from it.

For example, given the string $s = mnonopoo$, we have the following special palindromic substrings: $\{m, n, o, n, o, p, o, o, non, ono, opo, oo\}$.

**Function Description**

Complete the substrCount function in the editor below. It should return an integer representing the number of special palindromic substrings that can be formed from the given string.

substrCount has the following parameter(s):

- n: an integer, the length of string s
- s: a string

**Input Format**

The first line contains an integer, $n$, the length of $s$.
The second line contains the string $s$.

**Constraints**

$1 \leq n \leq 10^6$\
Each character of the string is a lowercase alphabet, $ascii[a-z]$.

**Output Format**

Print a single line containing the count of total special palindromic substrings.

**Sample Input 0**

```
5
asasd
```

**Sample Output 0**

```
7
```

**Explanation 0**

The special palindromic substrings of $s = asasd$ are $\{a, s, d, s, d, asa, sas\}$

**Sample Input 1**

```
7
abcbaba
```

**Sample Output 1**

```
10
```

**Explanation 1**

The special palindromic substrings of $s = abcbaba$ are $\{a, b, c, b, a, b, a, bcb, bab, aba\}$

**Sample Input 2**

```
4
aaaa
```

**Sample Output 2**

```
10
```

**Explanation 2**

The special palindromic substrings of $s = aaaa$ are $\{a, a, a, a, aa, aa, aa, aaa, aaa, aaaa\}$

# 특수 회문

문자열은 두 가지 조건 중 하나가 충족되면 특수 회문 문자열이라고 합니다.

- 모든 문자는 같습니다(예: aaa).
- 가운데 하나를 제외한 모든 문자는 동일합니다(예: aadaa).

특수 회문 하위 문자열은 해당 기준 중 하나를 충족하는 문자열의 하위 문자열입니다. 주어진 문자열을 통해 얼마나 많은 특수 회문 하위 문자열을 만들 수 있는지 결정합니다.

예를 들어 문자열 $s = mnonopoo$가 주어지면 $\{m, n, o, n, o, p, o, o, non, ono, opo, oo\}$와 같은 특수 회문 문자열을 얻을 수 있습니다.

**함수 설명**

아래 편집기에서 substrCount 함수를 완료하십시오. 주어진 문자열로부터 형성될 수 있는 특별한 회문 하위 문자열의 수를 나타내는 정수를 반환해야 합니다.

substrCount에는 다음 매개 변수가 있습니다.

- n: 정수, 문자열 s의 길이
- s: 문자열

**입력 형식**

첫 번째 줄에는 $s$의 길이인 정수 $n$이 있습니다.\
두 번째 줄에는 $s$ 문자열이 있습니다.

**제약 조건**

$1 \leq n \leq 10^6$\
문자열의 각 문자는 소문자 알파벳 $ascii [a-z]$입니다.

**출력 형식**

총 특수 회문 하위 문자열 수를 포함하는 한 줄을 인쇄하십시오.

**샘플 입력 0**

```
5
asasd
```

**샘플 출력 0**

```
7
```

**설명 0**

$s = asasd$의 특수 회문 부분 문자열은 $\{a, s, d, s, d, asa, sas\}$입니다.

**샘플 입력 1**

```
7
abcbaba
```

**샘플 출력 1**

```
10
```

**설명 1**

$s = abcbaba$의 특수 회문 부분 문자열은 $\{a, b, c, b, a, b, a, bcb, bab, aba\}$입니다.

**샘플 입력 2**

```
4
aaaa
```

**샘플 출력 2**

```
10
```

**설명 2**

$s = aaaa$의 특수 회문 부분 문자열은 $\{a, a, a, a, aa, aa, aa, aaa, aaa, aaaa\}$입니다.


# 해결법

1. 연속된 문자열을 확인해 배열에 개수를 저장한다.
2. 중간 문자만 다른 문자열을 구한다. $s = aba$인 경우 배열의 0번값과 2번값 중 작은 것을 구한다.)