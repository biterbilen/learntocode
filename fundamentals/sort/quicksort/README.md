# Problem

[Sort The Array @ geeksforgeeks](https://practice.geeksforgeeks.org/problems/sort-the-array/0)

# Idea


다음과 같은 정렬되지 않은 수열이 있다고 해보자.

```
5 2 1 4 3
```

하나의 기준값을 정하고 이것을 피봇이라고 하자. 수열을 처음부터
순회하면서 피봇보다 작은 녀석들은 수열의 앞쪽으로 피봇보다 큰 녀석들은
수열의 뒤쪽으로 배치한다. 이렇게 하는 것을 파티셔닝이라고 한다.
파티셔닝을 하면서 정렬이 수행된다. 또한 파티셔닝을 하는 방법에 따라
Hoare 방법과 Lomuto 방법이 있다.

파티셔닝후 피봇의 왼쪽으로 놓여있는 수열과 오른쪽으로 놓여있는
수열에 대해 다시 재귀적으로 정렬한다.

다음은 첫번째 파티셔닝의 절차이다.

```
5 2 1 4 3
2 5 1 4 3
2 1 5 4 3
2 1 3 4 5
```

이후 `2 1` 과 `4 5` 에 대하여 각각 퀵소트를 다시 수행한다.

# Hoare partition scheme

수열의 중간에 놓여있는 수를 피봇으로 정한다.

# Lomuto partition scheme

수열의 마지막에 놓여있는 수를 피봇으로 정한다.

## Implementation

[c++11](a.cpp)

## Time Complexity

```
O(NlgN)
```

## Space Complexity

```
O(lgN)
```
