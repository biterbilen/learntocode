# Abstract

knapsack problem에 대해 적어본다. 

knapsack problem은 여러가지 종류가 있다. 각각의 물건을 0개 혹은 1개
담을 수 있는 것을 0/1 knapsack problem, 각각의 물건을 0개 혹은 1개
이상 담을 수 있는 것을 unbounded knapsack problem, 각각의 물건을
쪼개서 담을 수 있는 것을 fractional knapsack problem이라고 한다.

# 0/1 knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건들이 있다고 하자. 그리고
각각의 물건 무게를 W_i, 가치를 V_i라고 하자. 이제 물건들을 배낭에
담아보자. 단, 물건 i는 0개 혹은 1개만 담을 수 있다. 무게는 배낭이
감당할 수 있는 최대가 되어야 하고 담겨진 물건들의 가치 합 역시 최대가
되도록 물건들을 조합해 보자.

## Idea

* recursion

모든 물건들을 하나씩 순회 한다. 그 물건을 포함 했을때 가치의 합과 그
물건을 포함 하지 않았을때의 가치의 합을 비교하여 최대 가치를 최종
결과에 더한다. 물건 i을 포함 할 경우 가방의 무게 C에서 W_i를 제거해야
한다. 가방의 무게 C는 점점 작아져 0에 가까울 때까지 반복한다.  이
방법은 무게를 C에서 시작하여 0에 가까울 때까지 구하는 방식이기 때문에
top-down style이다.

* iteration

모든 물건들을 하나씩 순회 한다. 그 물건을 기준으로 0부터 가능한 가방
무게까지 다시 순회 한다. 각 가방 무게에 대해서 그 물건이 포함
가능하지 않다면 그 전 물건까지 포함된 최대 가치를 저장하고 그 물건이
포함 가능 하다면 그 물건이 포함된 경우 가치의 합과 포함되지 않은 경우
가치의 합을 비교하여 큰 값을 저장한다. 이 방법은 무게를 0에서 부터
시작하여 각 경우에 대한 최대 가치를 구하는 방식이기 때문에 bottom-up
style이다.


## Implementation

[c++11](../fundamentals/dynamicprog/knapsack01/a.cpp)

## Time Complexity

```
O(2^N) recursion
O(CN)  iteration
```

## References

[Dynamic Programming | Set 10 ( 0-1 Knapsack Problem)](https://www.geeksforgeeks.org/knapsack-problem/)

# unbounded knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건들이 있다고
하자. 그리고 각각의 물건 무게를 W_i, 가치를 V_i라고 하자. 이제
물건들을 배낭에 담아보자. 단, 물건 i는 0개 이상 담을 수 있다. 무게는
배낭이 감당할 수 있는 최대가 되어야 하고 담겨진 물건들의 가치 합 역시
최대가 되도록 물건들을 조합해 보자.

## Idea

* recursion

???

* iteration

0부터 가방의 무게까지 순회 한다. 각 무게에 대해 모든 물건들을 다시
순회 한다. 그 물건이 특정 가방의 무게에 포함 가능하면 포함 한 경우
가치의 합과 포함 하지 않는 경우 가치의 합을 비교하여 더 큰 값을
저장한다. 물건은 0개 부터 무한대 까지 삽입 가능하다. 이때 저장한 것은
특정 무게에 대해 가방에 삽입된 물건들의 최대 가치 합을 의미한다.

## Implementation

[c++11](../fundamentals/dynamicprog/knapsackunbounded/a.cpp)

## Time Complexity

```
O(CN)  iteration
```

# fractional knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건들이 있다고
하자. 그리고 물건 각각의 무게를 W_i, 가치를 V_i라고 하자. 이제
물건들을 배낭에 담아보자. 단, 물건 i는 0개 이상 담을 수 있다. 그런데
물건을 쪼개서 담을 수도 있다. 예를 들어서 물건 i를 1/2개 담을 수 도
있다. 무게는 배낭이 감당할 수 있는 최대가 되어야 하고 담겨진 물건들의
가치 합 역시 최대가 되도록 물건들을 조합해 보자.

## Idea

greedy algorithm을 이용하여 해결하자.  단위 무게당 가치가 제일 높은
녀석부터 선택하여 배낭에 담는다.

## Implementation

[c++11](../fundamentals/greedy/knapsackfractional/a.cpp)

## Time Complexity

```
O(NlgN)
```
