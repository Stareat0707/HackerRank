# Jumping on the Clouds

Emma is playing a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus $1$ or $2$. She must avoid the thunderheads. Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. It is always possible to win the game.

For each game, Emma will get an array of clouds numbered $0$ if they are safe or $1$ if they must be avoided. For example, $c = [0, 1, 0, 0, 0, 1, 0]$ indexed from $0...6$. The number on each cloud is its index in the list so she must avoid the clouds at indexes $1$ and $5$. She could follow the following two paths: $0 \to 2 \to 4 \to 6$ or $0 \to 2 \to 3 \to 4 \to 6$. The first path takes $3$ jumps while the second takes $4$.

**Function Description**

Complete the jumpingOnClouds function in the editor below. It should return the minimum number of jumps required, as an integer.

jumpingOnClouds has the following parameter(s):

- c: an array of binary integers

**Input Format**

The first line contains an integer $n$, the total number of clouds. The second line contains $n$ space-separated binary integers describing clouds $c[i]$ where $0 \leq i < n$.

**Constraints**

- $2 \leq n \leq 100$
- $c[i] \in \{0, 1\}$
- $c[0] = c[n - 1] = 0$

**Output Format**

Print the minimum number of jumps needed to win the game.

**Sample Input 0**

```
7
0 0 1 0 0 1 0
```

**Sample Output 0**

```
4
```

**Explanation 0**

Emma must avoid $c[2]$ and $c[5]$. She can win the game with a minimum of $4$ jumps:

![](explanation_0.png)

**Sample Input 1**

```
6
0 0 0 0 1 0
```

**Sample Output 1**

```
3
```

**Explanation 1**

The only thundercloud to avoid is $c[4]$. Emma can win the game in $3$ jumps:

![](explanation_1.png)

# 구름 위로 뛰어오르기

Emma는 연속적으로 번호가 매겨진 구름으로 시작하는 새로운 모바일 게임을 하고 있습니다. 구름 일부는 천둥과 다른 것은 적 운입니다. 그녀는 현재의 구름 수에 $1$ 또는 $2$를 더한 수의 적은 구름으로 뛰어올 수 있습니다. 천둥 머리를 피해야 합니다. Emma가 출발점에서 마지막 구름으로 뛰어오르는 최소 점프 횟수를 결정합니다. 항상 게임에서 이기는 것이 가능합니다.

각 게임에 대해 Emma는 안전한 경우 $0$의 번호가 매겨진 구름 배열을 가져오고, 피해야 하는 경우 $1$의 번호를 부여합니다. 예를 들어, $0...6$까지 색인 된 $c = [0, 1, 0, 0, 0, 0]$. 각 구름의 숫자는 목록의 색인이므로 색인 $1$과 $5$에서 구름을 피해야 합니다. 그녀는 다음 두 경로를 따를 수 있습니다: $0 \to 2 \to 4 \to 6$ 또는 $0 \to 2 \to 3 \to 4 \to 6$. 첫 번째 경로는 $3$번 점프하고 두 번째 경로는 $4$번 점프합니다.

**함수 설명**

아래 편집기에서 jumpingOnClouds 함수를 완료하십시오. 필요한 최소 점프 수를 정수로 반환해야 합니다.

jumpingOnClouds에는 다음과 같은 매개 변수가 있습니다.

c: 2진수의 배열

**입력 형식**

첫 번째 줄에는 총 구름 수 인 정수 $n$이 포함됩니다. 두 번째 행에는 $0 \leq i < n$인 구름 $c[i]$를 설명하는 $n$개의 공백으로 구분된 2진 정수가 들어 있습니다.

**제약 조건**

- $2 \leq n \leq 100$
- $c[i] \in \{0, 1\}$
- $c[0] = c[n - 1] = 0$

**출력 형식**

게임에서 이기기 위해 필요한 최소 점프 수를 인쇄하십시오.

**샘플 입력 0**

```
7
0 0 1 0 0 1 0
```

**샘플 출력 0**

```
4
```

**설명 0**

Emma는 $c[2]$와 $c[5]$를 피해야 합니다. 그녀는 최소 $4$ 점프로 게임에서 이길 수 있습니다.

![](explanation_0.png)

**샘플 입력 1**

```
6
0 0 0 0 1 0
```

**샘플 출력 1**

```
3
```

**설명 1**

피해야 할 유일한 뇌우는 $c[4]$입니다. Emma는 $3$ 점프로 게임에서 이길 수 있습니다.

![](explanation_1.png)

# 해결법

실패하는 경우가 없고, 최소 1칸에서 최대 2칸까지 이동하므로 2칸 진출이 가능한 경우엔 2칸 진출, 그 외엔 모두 1칸 진출하여 횟수를 계산한다.