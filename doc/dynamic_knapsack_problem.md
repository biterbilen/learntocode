# Abstract

knapsack problem에 대해 적어본다. 

knapsack problem은 여러가지 종류가 있다. 물건을 0개 혹은 1개 담을
수 있는 것을 0/1 knapsack problem, 물건을 0개 혹은 1개 이상 담을 수
있는 것을 unbounded knapsack problem, 물건을 쪼개서 담을 수 있는 것을
fractional knapsack problem등이 있다.

# 0/1 knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건이 있다고 하자. 그리고
물건 각각의 무게를 W_i, 가치를 V_i라고 하자. 이제 물건들을 배낭에
담아보자. 단, 물건 i는 0개 혹은 1개만 담을 수 있다. 무게는 배낭이
감당할 수 있는 최대가 되어야 하고 담겨진 물건들의 가치의 합 역시
최대가 되도록 선택해보자.

## Idea

* recursion

물건들을 순회할때 

* iteration

## Implementation

[c++11](../fundamentals/dynamic/knapsack01/a.cpp)

## Time Complexity

```
O(NC)
```

## References

[Dynamic Programming | Set 10 ( 0-1 Knapsack Problem)](https://www.geeksforgeeks.org/knapsack-problem/)

# unbounded knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건이 있다고 하자. 그리고
물건 각각의 무게를 W_i, 가치를 V_i라고 하자. 이제 물건들을 배낭에
담아보자. 단, 물건 i는 0개 이상 담을 수 있다. 무게는 배낭이
감당할 수 있는 최대가 되어야 하고 담겨진 물건들의 가치의 합 역시
최대가 되도록 선택해보자.

## Idea

## Implementation

[c++11](../fundamentals/dynamic/knapsackunbounded/a.cpp)

## Time Complexity

```
```

# fractional knapsack problem

## Problem

특정 무게 C까지 감당할 수 있는 배낭과 N개의 물건이 있다고 하자. 그리고
물건 각각의 무게를 W_i, 가치를 V_i라고 하자. 이제 물건들을 배낭에
담아보자. 단, 물건 i는 0개 이상 담을 수 있다. 그런데 물건을 쪼개서
담을 수도 있다. 예를들어서 물건 i를 1/2개 담을 수 도 있다. 무게는
배낭이 감당할 수 있는 최대가 되어야 하고 담겨진 물건들의 가치의 합
역시 최대가 되도록 선택해보자.

## Idea

greedy algorithm을 이용하여 해결하자.  단위 무게당 가치가 제일 높은
녀석부터 선택하여 배낭에 담는다.

## Implementation

[c++11](../fundamentals/greedy/knapsackfractional/a.cpp)

## Time Complexity

```
O(NlgN)
```
