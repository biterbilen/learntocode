# Problem

어떤 작업을 수행하는데 선행해야 하는 작업이 존재할 때 선행작업을 먼저 
수행하는 식으로 정렬하는 방법이다. 정렬의 결과는 여러개일 수 있다.

# Idea

`a->b` 형태의 데이터는 `b` 작업을 하기 전에 `a` 작업이 먼저 수행되야 함을 의미한다.
[DFS](fundamentals/graph/dfs/README.md) 를 이용해서 방문한다. [DFS](fundamentals/graph/dfs/README.md) 할 때 특정 노드를 방문할 때 마다 
깊이가 깊은 다른 노드들을 모두 방문 후 그 노드를 삽입하기 때문에
방문된 작업들의 순서를 뒤집어야 위상정렬의 결과와 같아진다. 
뒤집혀진 결과를 하나씩 순회 하면서 [DFS Spanning Tree]()에서 다루었던
Back-Edge 가 존재하는지 검사한다. Back-Edge가 있다면 사이클이 존재하는 
것이고 이것은 위상정렬이 불가능하다는 얘기이다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(V+E)
```

# Space Complexity

```
O(V)
```

# Rerences

* [Topological Sorting @ geeksforgeeks](https://www.geeksforgeeks.org/topological-sorting/)