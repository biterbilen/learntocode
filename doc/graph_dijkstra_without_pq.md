# Abstract

우선순위 큐를 사용하지 않는 방법이 더 빠른 경우가 있다.  우선순위 큐를
이용하는 [dijkstra](graph_dijkstra.md)와 here를 찾는 방법이
다르다. 특정정점에서 나머지정점들의 거리를 저장하는 dist[]에서 가장
거리가 작고 아직 방문하지 않는 녀석을 here로 한다.

# Idea

visited를 이용하여 방문 하지 않은 정점 중 dist가 가장 작은 값을
찾는다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(|V|^2 + |E|)
```
