# Problem

노드 `V(vertex)` 와 간선 `E(edge)` 이 주어졌을 때 특정 노드를 시작으로 깊이우선탐색하여 모든 노드를 방문한다.

# Idea

예를 들어 다음과 같은 그래프를 가정하자.

```
         0
       / | \
      1  2  3
    / | \
   4  5  6 
```

`0` 을 방문하고 이웃들 중 깊이가 가장 긴 녀석 `1` 을 방문한다. 그리고 이웃들 중 깊이가 가장 긴 녀석 `4` 를 방문한다. 이렇게 깊이를 우선순위가 가장 높게 방문하는 방법을 DFS (Depth First Search) 라고 한다.

# Recursive Way

DFS 를 재귀함수를 이용하여 수행한다.

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

DFS 를 스택을 이용하여 반복적으로 수행한다.

## Implementation

[c++11](a.cpp)

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