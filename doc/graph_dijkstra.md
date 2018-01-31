# Abstract

가중치 그래프의 경우 출발 정점이 하나 주어 지면 나머지 정점들로
방문하는 최단 거리를 계산하는 알고리즘이다. 이때 가중치는 양수이어야
한다. 음수 가중치의 경우 [bellman ford](/doc/graph_bellman_ford.md)
알고리즘을 사용할 수 있다. 가중치가 없다면 [bfs](/doc/graph_bfs.md) 로
충분하다.

# Idea

출발 정점이 하나 주어진다. 우선 순위 큐를 `pq` 로 표기하자.  우선 순위
큐에 `pair<출발 정점에서 목표 정점까지 거리, 목표 정점>` 을
삽입한다. 거리는 `-1` 을 곱하여 저장한다. 우선순위 큐는 기본적으로
내림차순이다. 거리가 작은 녀석이 우선순위가 높아야 한다.

목표 정점 까지의 거리는 `vector<int> dist` 배열에 저장한다.  `dist[i]`
는 출발 정점에서 `i` 노드 까지의 거리이다.  `dist` 는 반복문을 수행할
때마다 같은 목표 정점 일지라도 계속 해서 이전 보다 작은 값으로
갱신된다.  출발 정점이 `0` 이라면 `dist[0]` 은 `0` 이다.

우선 순위 큐가 비워질 때 까지 하나씩 추출할 때 마다 다음을 반복한다.

추출한 것을 `pair<cost, here>` 로 표기하자.  `cost` 는 출발 정점에서
`here` 까지의 거리이다.  이것이 기존에 갱신했던 `dist[here]` 보다
크다면 기존에 발견한 경로의 거리가 더욱 짧은 것이므로 더 이상 탐색
하는 것은 의미가 없다. `cost` 가 `dist[here]` 보다 작다면 `here` 의
이웃들을 대상으로 다음과 같이 반복한다. 

이웃을 `there` 라고 하고 출발 정점에서 `there` 까지의 거리를
`cost_there` 라고 하자. `cost_there` 가 `dist[there]` 보다 작으면
`dist[there]` 를 `cost_there` 로 갱신하고 `pair<-there_cost, there` 를
`pq` 에 삽입한다.

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
