# Abstract

노드 a에서 노드 b까지 BFS(breadth first search)를 이용하여 최단 경로를
찾아 보자.

# Idea

출발지에 해당하는 a노드 부터 [BFS](/fundamentals/graph/BFS/README.md)를 이용하여 모든 노드들을
방문한다. 방문 하는 노드의 부모 노드를 parent에 저장하자.

parent를 이용하여 b노드 부터 a노드 까지의 경로를 역추적한다.  간선의
비용이 일정하기 때문에 parent를 이용한 경로는 최단 경로에 해당한다.

# Keyword

```
adj, get_shortest_path, bfs, parent, found, q
```

# Implementation

[c++11](a.cpp)

# Time Complexity

V를 노드 E를 간선 이라고 하자.

```
O(V+E) : adjacency list
O(V^2) : adjacency matrix
```

# Space Complexity

```
O(V)
```