# Problem

노드 `V(vertex)` 와 간선 `E(edge)` 이 주어졌을 때 특정 노드를 시작으로 깊이우선탐색하여 모든 노드를 방문한다.

# Recursive Way

## Idea

인접한 노드들을 재귀함수를 이용하여 방문한다.

## Implementation

[c++11](a.cpp)
[python](a.py)
[go](a.go)
[java](java/A.java)
[c#](cs/a.cs)

## Time Complexity

```
O(V+E)
```

## Space Complexity

```
O(V)
```

# Iterative Way

## Idea

인접한 노드들을 스택을 이용하여 방문한다.

## Implementation

## Time Complexity

```
O(V+E)
```

## Space Complexity

```
O(V)
```

# References

* [Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)