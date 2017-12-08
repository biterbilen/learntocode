# Abstract

모든 점들중 가장 가까운 거리의 두 점을 조사하자.

# Idea

Brute Force전략을 구사한다면 O(N^2)이다. Devide Conquer전략을 구사한다면 
O(N(lnN)^2)이다. 좀 더 잘한다면 O(NlgN)으로 해결할 수도 있다.

# Implementation

[src](../fundamentals/computationalgeometry/closest_pair/a.cpp)

# Time Complexity

O(N(lgN)^2)

# References

* [closest pair of points @ geeksforgeeks](http://www.geeksforgeeks.org/closest-pair-of-points/)
* [closest pair of points O(NlgN) @ geeksforgeeks](http://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/)
