# Problem

* [Lowest Common Ancestor in a Binary Tree @ geeksforgeeks](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1)

# Strategy with single traversal

## Idea

다음과 같이 부분문제 `lca`를 정의하여 재귀적으로 해결해보자.

```
lca(root, u, v)
```



## Implementation

[c++11](a.cpp)

## Time Complexity

```
O(N)
```

# Strategy with RMQ

## Idea

하나의 입력데이터에 다수의 질의가 존재하는
경우라면 [RMQ](/doc/tree_rmq.md)를 이용하여 각 질의 마다 `O(lgN)`의
시간으로 해결할 수 있다.

## Implementation

[c++11](b.cpp)

## Time Complexity

```
O(N)   : build segment tree
O(loN) : query 
```

# References

* [Lowest Common Ancestor in a Binary Tree | Set 1 @ geeksforgeeks](https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/)
* [Find LCA in Binary Tree using RMQ @ geeksforgeeks](https://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/)

