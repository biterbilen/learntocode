# Problem

[binary Search with array @ geeksforgeeks](hhttps://practice.geeksforgeeks.org/problems/binary-search/1)

# Idea

배열을 `v[]`, 검색하고자 하는 값을 `k` 라 하고 왼쪽, 가운데, 오른쪽을 의미하는 첨자를 `l, m, r` 이라고 하자. `m = (l + r)/2` 이고 `k < v[m]` 이면 `r = m - 1` 이다. `k > v[m]` 이면 `l = m + 1` 이다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(logN)
```

# Space Complexity

```
O(1)
```