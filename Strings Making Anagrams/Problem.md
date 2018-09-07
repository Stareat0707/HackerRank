# Strings: Making Anagrams

Check out the resources on the page's right side to learn more about strings. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book [Cracking the Coding Interview](https://www.hackerrank.com/ctci-book?ref=body).

Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, $a$ and $b$, that may or may not be of the same length, determine the minimum number of character deletions required to make $a$ and $b$ anagrams. Any characters can be deleted from either of the strings.

For example, if $a = cde$ and $b = def$, we can delete $e$ from string $a$ and $f$ from string $b$ so that both remaining strings are $cd$ and $dc$ which are anagrams.

**Function Description**

Complete the makeAnagram function in the editor below. It must return an integer representing the minimum total characters that must be deleted to make the strings anagrams.

makeAnagram has the following parameter(s):

- a: a string
- b: a string

**Input Format**

The first line contains a single string, $a$.\
The second line contains a single string, $b$.

**Constraints**

- $1 \leq |a|, |b| \leq 10^4$
- The strings $a$ and $b$ consist of lowercase English alphabetic letters ascii[a-z].

**Output Format**

Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.

**Sample Input**

```
cde
abc
```

**Sample Output**

```
4
```

**Explanation**

We delete the following characters from our two strings to turn them into anagrams of each other:

1. Remove d and e from cde to get c.
2. Remove a and b from abc to get c.

We must delete $4$ characters to make both strings anagrams, so we print $4$ on a new line.

# 문자열: 어구전철 만들기

문자열에 대해 자세히 알아보려면 페이지 오른쪽의 자료를 확인하십시오. 비디오 자습서는 Gayle Laakmann McDowell의 베스트셀러 인터뷰 책인 [Cracking the Coding Interview](https://www.hackerrank.com/ctci-book?ref=body)의 저자입니다.

Alice는 암호화 클래스를 사용하고 어구전철을 찾는 것이 매우 유용합니다. 첫 번째 문자열의 문자가 두 번째 문자열을 형성하기 위해 재배열 될 수 있다면 두 개의 문자열이 서로의 어구전철이라고 생각합니다. 다시 말해, 두 문자열은 같은 정확한 빈도로 똑같은 정확한 문자를 포함해야 합니다. 예를 들어, bacdc 및 dcbac는 어구전철이지만 bacdc 및 dcbad는 그렇지 않습니다.

Alice는 암호화가 두 개의 문자열을 분석하기 위해 필요한 문자 삭제의 최소 수에 의존하는 두 개의 큰 문자열을 포함하는 암호화 체계를 결정합니다. 그녀가 이 번호를 찾도록 도울 수 있습니까?

주어진 길이가 같거나 다를 수 있는 두 개의 문자열 $a$와 $b$가 주어지면 $a$와 $b$의 어구전철을 만들기 위해 필요한 문자 삭제의 최소 수를 결정합니다. 문자열 중 하나에서 문자를 삭제할 수 있습니다.

예를 들어 $a = cde$ 및 $b = def$인 경우 나머지 문자열이 어구전철인 $cd$ 및 $dc$가 되도록 문자열 $a$에서 $e$ 및 $b$에서 $f$를 삭제할 수 있습니다.

**함수 설명**

아래 편집기에서 makeAnagram 함수를 완성하십시오. 문자열을 분석하기 위해 삭제해야 하는 최소 총 문자 수를 나타내는 정수를 반환해야 합니다.

makeAnagram에는 다음 매개 변수가 있습니다.

- a: a string
- b: a string

**입력 형식**

첫 번째 줄에는 단일 문자열인 $a$가 들어 있습니다.
두 번째 줄에는 단일 문자열 $b$가 들어 있습니다.

**제약 조건**

- $1 \leq |a|, |b| \leq 10^4$
- 문자열 $a$ 및 $b$는 소문자 로마자 알파벳 문자 ASCII [a-z]로 구성됩니다.

**출력 형식**

두 개의 문자열을 서로의 어구전철로 만들기 위해 삭제해야 하는 문자 수를 나타내는 단일 정수를 인쇄하십시오.

**샘플 입력**

```
cde
abc
```

**샘플 출력**

```
4
```

**설명**

두 개의 문자열에서 다음 문자를 삭제하여 서로의 어구전철로 변환합니다.

1. cde에서 d와 e를 제거하여 c를 얻습니다.
2. abc에서 a와 b를 제거하여 c를 얻습니다.

두 문자열을 모두 분석하기 위해 $4$자를 삭제해야 하므로 새 줄에 $4$를 인쇄합니다.

# 해결법

map을 사용하여 해결한다.

a에서 나온 문자들의 수를 map에 저장하고, b에서 해당 문자가 나올 때마다 map에서 제거한다.

마지막으로 map의 value들의 절대값을 모두 더한다.