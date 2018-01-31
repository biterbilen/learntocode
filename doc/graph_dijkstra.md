# Abstract

가중치 그래프의 경우 최단 경로를 구하는 알고리즘이다. 이때 가중치는
양수이어야 한다. 음수 가중치의
경우 [bellman ford](/doc/graph_bellman_ford.md) 알고리즘을 사용할 수
있다. 가중치가 없다면 bfs로 충분하다.  특정 정점에서 나머지 정점들로
방문하는 최단 거리를 계산한다.

# Idea

우선순위 큐를 사용한다. 우선순위 큐에 `pair<특정정점에서
지금정점까지거리, 지금정점>` 을 삽입한다. 거리는 `-1` 을 곱하여
저장한다. 우선순위 큐는 기본적으로 내림차순이다. 거리가 작은 녀석이
우선순위가 높아야 한다.

지금정점의 인접한 정점들 즉 미래정점들까지 거리보다 작은 경로가
존재하지 않는다면 미래정점들을 우선선위 큐에 삽입한다. 이때 거리는
`-1` 을 곱하여 저장한다.

다음은 정점 3개로 이루어진 그래프이다. 간선 `0-1` 의 가중치를 `1`
이라고 하고 간선 '0-2' 의 가중치를 `2` 라고 하자. `dist[i]` 는 정점
`0` 에서 `i` 정점까지의 거리이다. `pq, dist` 가 채워지는 과정을 다음과
같이 기술한다.

```
pq   : (0, 0)
dist :
   0
1 / \ 2
 1   2
```

# Implementation

* [c++11](/fundamentals/graph/dijkstra/a.cpp)

# Time Complexity

```
O(|E|lg|V|)
```

간선의 개수만큼 방문 하고 정점의 개수 만큼 우선순위 큐 정렬이 필요하기
때문이다.  피보나치 힙 혹은 이진 검색 트리를 이용하여 `O(|V|lg|V|)`에
구현할 수 있다. 하지만 구현이 복잡하거나 실제로 작성해 보면 속도가 더
느린 경우가 많아 쉽지 않다.

# reference

* [dijkstra in 2 minutes at youtube](https://www.youtube.com/watch?v=_lHSawdgXpI)
* [dijkstra video in geeksforgeeks](https://www.youtube.com/embed/gdmfOwyQlcI)
