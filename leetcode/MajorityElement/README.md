# Problem

숫자들의 배열 `V` 가 주어지고 크기를 `N` 이라고 하자. 
`V` 의 숫자들중 출현 횟수가 `N/2` 보다 큰 숫자를 찾아라.
그러한 숫자를 `Majority Element` 라고 부르고 반드시 존재한다고 가정하자.

# Idea

```
{1, 1, 1, 2, 3}
```

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)
```

# Space Complexity

```
O(1)
```

# References

* [Boyer–Moore majority vote algorithm @ wikipedia](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
* [MJRTY - A FAST MAJORITY VOTE ALGORITHM](http://www.dtic.mil/dtic/tr/fulltext/u2/a131702.pdf)