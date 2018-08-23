# Problem

[Sort The Array @ geeksforgeeks](https://practice.geeksforgeeks.org/problems/sort-the-array/0)

# Abstract

퀵소트는 파티셔닝을 하는 방법에 따라 Hoare 방법과 Lomuto 방법이 있다.

# Hoare partition scheme

## Idea



## Implementation

[c++11](a.cpp)

## Time Complexity

## Space Complexity

# Lomuto partition scheme

## Idea

다음과 같은 정렬되지 않은 수열이 있다고 해보자.

```
5 2 1 4 3
```

맨 마지막 값을 피봇으로 정한다. 수열의 처음부터 피봇전까지 순회하면서
피봇보다 작으면 수열의 앞쪽으로 피봇보다 크면 수열의 뒤쪽으로
이동한다. 수열의 파티셔닝 작업이 끝났으면 수열의 처음부터 피봇의
전까지 그리고 피봇의 다음부터 수열의 끝까지 각각 퀵소트한다. 

다음은 첫번째 파티셔닝의 절차이다.

```
5 2 1 4 3
2 5 1 4 3
2 1 5 4 3
2 1 3 4 5
```

이후 `2 1` 과 `4 5` 에 대하여 각각 퀵소트를 다시 수행한다.

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
