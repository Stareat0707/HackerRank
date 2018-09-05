Fraudulent Activity Notifications
=================================
HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to $2X$ the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days $d$ and a client's total daily expenditures for a period of $n$ days, find and print the number of times the client will receive a notification over all $n$ days.

For example, $d = 3$ and $expenditures = [10, 20, 30, 40, 50]$. On the first three days, they just collect spending data. At day $4$, we have trailing expenditures of $[10, 20, 30]$. The median is $20$ and the day's expenditure is $40$. Because $40 ≥ 2 × 20$, there will be a notice. The next day, our trailing expenditures are $[20, 30, 40]$ and the expenditures are 50. This is less than $2 × 30$ so no notice will be sent. Over the period, there was one notice sent.

**Note**: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. If there is an odd number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the average of the two middle values. [(Wikipedia)](https://en.wikipedia.org/wiki/Median#Basic_procedure)

**Function Description**

Complete the function activityNotifications in the editor below. It must return an integer representing the number of client notifications.

activityNotifications has the following parameter(s):

- expenditure: an array of integers representing daily expenditures
- d: an integer, the lookback days for median spending

**Input Format**

The first line contains two space-separated integers $n$ and $d$, the number of days of transaction data, and the number of trailing days' data used to calculate median spending. 
The second line contains $n$ space-separated non-negative integers where each integer $i$ denotes $expenditure[i]$.

**Constraints**

- $1 ≤ n ≤ 2 × 10^5$
- $1 ≤ d ≤ n$
- $0 ≤ expenditure[i] ≤ 200$

**Output Format**

Print an integer denoting the total number of times the client receives a notification over a period of $n$ days.

**Sample Input 0**

```
9 5
2 3 4 2 3 6 8 4 5
```

**Sample Output 0**

```
2
```

**Explanation 0**

We must determine the total number of $notifications$ the client receives over a period of $n = 9$ days. For the first five days, the customer receives no notifications because the bank has insufficient transaction data: $notifications = 0$.

On the sixth day, the bank has $d = 5$ days of prior transaction data, $\{2, 3, 4, 2, 3\}$, and $median = 3$ dollars. The client spends $6$ dollars, which triggers a notification because $6 ≥ 2 × median$: $notifications = 0 + 1 = 1$.

On the seventh day, the bank has $d = 5$ days of prior transaction data, $\{3, 4, 2, 3, 6\}$, and $median = 3$ dollars. The client spends $8$ dollars, which triggers a notification because $8 ≥ 2 × median$: $notifications = 1 + 1 = 2$.

On the eighth day, the bank has $d = 5$ days of prior transaction data, $\{4, 2, 3, 6, 8\}$, and $median = 4$ dollars. The client spends $4$ dollars, which does not trigger a notification because $4 < 2 × median$: $notifications = 2$.

On the ninth day, the bank has $d = 5$ days of prior transaction data, $\{2, 3, 6, 8, 4\}$, and a transaction median of $4$ dollars. The client spends $5$ dollars, which does not trigger a notification $5 < 2 × median$: $notifications = 2$.

**Sample Input 1**

```
5 4
1 2 3 4 4
```

**Sample Output 1**

```
0
```

There are $4$ days of data required so the first day a notice might go out is day $5$. Our trailing expenditures are $[1, 2, 3, 4]$ with a median of $2.5$ The client spends $4$ which is less than $2 × 2.5$ so no notification is sent.

사기성 활동 알림
===============
해커랜드 국립 은행은 사기성 계정 활동을 고객에게 경고하기위한 간단한 정책이 있습니다. 어느 날 고객이 소비 금액이 이전 며칠간 고객의 평균 지출액의 $2$배 이상이면 잠재적인 사기에 대한 알림을 고객에게 보냅니다. 은행은 적어도 그 전날의 거래가 끝날 때까지 고객에게 알림를 보내지 않습니다.

$n$일 동안 $d$일 전까지 고객의 총 일일 지출을 감안할 때 고객이 $n$일 중 알람을 받을 횟수를 찾아서 출력하십시오.

예로, $d = 3$ 이고 $expenditures = [10, 20, 30, 40, 50]$이라고 합시다. 처음 3일 동안은, 단지 지출 정보만 수집합니다. $4$일째에는 $[10, 20, 30]$의 지출 정보가 있습니다. 중앙값은 20달러이고 당일일 지출액은 40달러입니다. $40 ≥ 2 × 20$이므로 알람을 보낼 것입니다. 다음 날의 지출 정보는 $[20, 30, 40]$이고 당일 지출액은 50달러입니다. $2 × 30$ 미만이므로 알람을 보내지 않습니다. 따라서 모든 기간 동안 한 번의 통보가 있습니다.

**메모**: 숫자 리스트의 중앙값은 모든 숫자를 가장 작은 것부터 가장 큰 것 순으로 정렬하여 찾을 수 있습니다. 숫자가 홀수개 있으면 중간 숫자가 선택됩니다. 짝수 개의 숫자가 있는 경우 중간값은 두 중간값의 평균으로 정의됩니다. [(위키백과)](https://en.wikipedia.org/wiki/Median#Basic_procedure)

**함수 설명**

아래 에디터에서 activityNotifications를 작성하십시오. 고객에게 보내는 알람 수를 나타내는 정수를 반환해야 합니다.

activityNotifications에는 다음 매개 변수가 있습니다.

- expenditure: 일일 지출을 나타내는 정수 배열
- d: 중간값 지출에 대한 데이터 보유 일수

**입력 형식**

첫 번째 줄에는 지출 데이터의 일수와 중간값 계산에 필요한 일수 $n$과 $d$ 두 개의 공백으로 구분되어 주어집니다.
두 번째 행에는 $n$개의 공백으로 구분된 정수가 들어 있으며, 각 정수 $i$는 $expenditure [i]$를 나타냅니다.

**제약 조건**

- $1 ≤ n ≤ 2 × 10^5$
- $1 ≤ d ≤ n$
- $0 ≤ expenditure[i] ≤ 200$

**출력 형식**

$n$일 동안 고객이 알림을 수신한 총 횟수를 나타내는 정수를 출력합니다.

**예시 입력 0**

```
9 5
2 3 4 2 3 6 8 4 5
```

**예시 출력 0**

```
2
```

**설명 0**

$n = 9$일 동안 고객이받는 $notification$의 수를 결정해야 합니다. 처음 5일 동안엔 은행에 충분한 거래 데이터가 없기 때문에 고객은 알림을 받지 못합니다. $notifications = 0$.

6일째 되는 날에 은행은 $d = 5$일 간의 이전 거래 데이터 $\{2, 3, 4, 2, 3 \}$ 및 $median = 3$달러를 갖습니다. 고객은 당일 $6$달러를 소비합니다. $6 ≥ 2 × median$이므로 알람을 송신합니다. : $notifications = 0 + 1 = 1$

7일째 되는 날에 은행은 $d = 5$일 간의 이전 거래 데이터 $\{3, 4, 2, 3, 6 \}$ 및 $median = 3$달러를 갖습니다. 고객은 당일 $8$달러를 소비합니다. $8 ≥ 2 × median$이므로 알람을 송신합니다. : $notifications = 1 + 1 = 2$

8일째 되는 날에 은행은 $d = 5$일간의 거래 데이터 $\{5, 4, 3, 6, 8\}$ 및 $median = 4$달러를 갖습니다. 고객은 당일 $5$달러를 소비하여 $4 < 2 × median$이므로, 알림을 송신하지 않습니다. : $notifications = 2$

9일째 되는 날에 은행은 $d = 5$일간의 거래 데이터 $\{2, 3, 6, 8, 4\}$ 및 $median = 4$달러를 갖습니다. 고객은 당일 $5$달러를 소비하여 $5 < 2 × median$이므로, 알림을 송신하지 않습니다. : $notifications = 2$

**예시 입력 1**

```
5 4
1 2 3 4 4
```

**예시 출력 1**

```
0
```

$4$일간의 데이터가 필요하므로 알림이 송신되는 첫날은 $5$일입니다. 우리의 후행 지출은 $[1, 2, 3, 4]$이고 중앙값은 $2.5$입니다. 고객은 $2 × 2.5$달러 미만의 $4$달러를 소비하므로 알림이 전송되지 않습니다.

해결책
=====

계수 정렬을 사용하여 해결한다.
시작지점 s부터 끝지점 e까지 나온 금액을 map에 저장하면 정렬도 되고 중간값도 찾을 수 있다. 중간값을 사용한 계산이 끝나면 ++s, ++e하여 다음날로 넘어간다.