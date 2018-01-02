# Abstract

그래프의 모든 노드들을 BFS(breadth first search)를 이용하여 방문해
보자.

# Idea

현재 방문할 노드의 인접한 노드들을 큐에 삽입하자.  한번 방문 한 노드는
표시하여 재방문 하지 않도록 한다.  큐가 비워질 때까지 노드 방문 및 큐
삽입을 계속 하자.

# Keyword

```
adj, bfs, order, found, q
```

# Implementation

[c++11](../fundamentals/graph/bfs/a.cpp)

# Time Complexity

V를 노드 E를 간선 이라고 하자.

```
O(|V| + |E|) adjacency list
O(|V|^2) adjacency matrix
```
