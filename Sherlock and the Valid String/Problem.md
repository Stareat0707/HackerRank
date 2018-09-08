# Sherlock and the Valid String

Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just $1$ character at $1$ index in the string, and the remaining characters will occur the same number of times. Given a string $s$, determine if it is valid. If so, return YES, otherwise return NO.

For example, if $s = abc$, it is a valid string because frequencies are ${a : 1, b : 1, c : 1}$. So is $s = abcc$ because we can remove one $c$ and have $1$ of each character in the remaining string. If $s = abccc$ however, the string is not valid as we can only remove $1$ occurrence of $c$. That would leave character frequencies of ${a : 1, b : 1, c : 2}$.

**Function Description**

Complete the isValid function in the editor below. It should return either the string YES or the string NO.

isValid has the following parameter(s):

- s: a string

**Input Format**

A single string $s$.

**Constraints**

- $1 \leq |s| \leq 10^5$
- Each character $s[i] \in ascii[a - z]$

**Output Format**

Print YES if string is valid, otherwise, print NO.

**Sample Input 0**

```
aabbcd
```

**Sample Output 0**

```
NO
```

**Explanation 0**

Given $s = "aabbcd"$, we would need to remove two characters, both c and d $\to$ aabb or a and b $\to$ abcd, to make it valid. We are limited to removing only one character, so $s$ is invalid.

**Sample Input 1**

```
aabbccddeefghi
```

**Sample Output 1**

```
NO
```

**Explanation 1**

Frequency counts for the letters are as follows:

{'a': 2, 'b': 2, 'c': 2, 'd': 2, 'e': 2, 'f': 1, 'g': 1, 'h': 1, 'i': 1}

There are two ways to make the valid string:

- Remove $4$ characters with a frequency of $1$: $\{fghi\}$.
- Remove $5$ characters of frequency $2$: $\{abcde\}$.

Neither of these is an option.

**Sample Input 2**

```
abcdefghhgfedecba
```

**Sample Output 2**

```
YES
```

**Explanation 2**

All characters occur twice except for $e$ which occurs $3$ times. We can delete one instance of $e$ to have a valid string.

# 셜록과 유효한 문자열

셜록은 문자열의 모든 문자가 같은 횟수만큼 나타나면 문자열이 유효한 것으로 간주합니다. 문자열의 1색인에서 1문자 만 제거 할 수 있고 나머지 문자는 같은 횟수만큼 발생하는 경우에도 유효합니다. 주어진 문자열 s가 유효한지 판단하십시오. 그렇다면 YES를 돌려보내고, 그렇지 않으면 NO를 돌려보냅니다.

예를 들어 s = abc 인 경우 빈도는 {a : 1, b : 1, c : 1}이므로 유효한 문자열입니다. 그래서 우리는 하나의 c를 제거 할 수 있고 나머지 문자열에서 각각의 문자 하나를 가질 수 있기 때문에 s = abcc입니다. 그러나 s = abccc 인 경우 문자열은 유효하지 않습니다. 왜냐하면 우리는 c의 1번만 제거 할 수 있기 때문입니다. 그러면 {a : 1, b : 1, c : 2}의 문자 빈도가 남습니다.

**함수 설명**

아래 편집기에서 isValid 함수를 완성하십시오. 문자열 YES 또는 문자열 NO를 반환해야 합니다.

isValid에는 다음과 같은 매개 변수가 있습니다.

- s: 문자열

**입력 형식**

단일 문자열 s.

**제약 조건**

- $1 \leq |s| \leq 10^5$
- 각각의 문자 $s[i] \in ascii[a - z]$

**출력 형식**

문자열이 유효하면 YES를 출력하고, 그렇지 않으면 NO를 인쇄합니다.

**샘플 입력 0**

```
aabbcd
```

**샘플 출력 0**

```
NO
```

**설명 0**

$s = "aabbcd"$라고 하면, c와 d $\to$ aabb 또는 a와 b $\to$ abcd의 두 문자를 제거해야 유효합니다. 한 문자 만 제거 할 수 있으므로 $s$는 유효하지 않습니다.

**샘플 입력 1**

```
aabbccddeefghi
```

**샘플 출력 1**

```
NO
```

**설명 1**

문자의 빈도수는 다음과 같습니다.

{'a': 2, 'b': 2, 'c': 2, 'd': 2, 'e': 2, 'f': 1, 'g': 1, 'h': 1, 'i': 1}

유효한 문자열을 만드는 방법에는 두 가지가 있습니다.

- 빈도수가 $1$인 $\{fghi\}$ 인 $4$자를 삭제하십시오.
- 빈도 $2$: $\{abcde\}$의 $5$자를 제거하십시오.

이들 중 어느 것도 옵션이 아닙니다.

**샘플 입력 2**

```
abcdefghhgfedecba
```

**샘플 출력 2**

```
YES
```

**설명 2**

모든 문자는 $3$번 발생하는 $e$를 제외하고 두 번 발생합니다. 우리는 하나의 $e$ 인스턴스를 삭제하여 유효한 문자열을 가질 수 있습니다.


# 해결법

문자들이 나온 횟수를 map에 정리한 뒤, 그 빈도를 다시 map에 저장한다.

이 map의 크기가 1인 경우 무조건 유효한 문자열이고, 2를 초과할 경우 무조건 유효하지 않은 문자열이다.

한 번만 나온 빈도를 이용해 문자열이 유효한지 확인한다.