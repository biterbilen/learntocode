# Problem

[Insertion Sort List @ leetcode](https://leetcode.com/problems/insertion-sort-list/description/)

# Idea

숫자들의 배열을 `A`라 하고 처음부터 순회 하자. 순회 할때 인덱스를 `i`
라고 하자.  이때 `i` 가 증가할 때 마다 'j' 를 만들어 'i' 부터 하나씩
감소시킨다.

`j` 가 감소할 때마다 `A[j]`와 `A[j-1]`의 숫자를 비교하여 
정렬 되지 않았으면 `A[j]`와 `A[j-1]`를 교체한다.

이때 두가지 불변식을 만들어 낼 수 있다.
첫번째는 `A[j+1..i]`는 모두 `A[j]` 보다 크다.
두번째는 `A[0..i]`는 모두 `A[j]`를 제외하면 정렬되어 있다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(N^2)
```

# Space Complexity

```
O(1)
```
