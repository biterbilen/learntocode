# Abstract

kruskal algorithm은 MST(minimum spanning tree)를 구하는 알고리즘이다.

spanning tree는 graph에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 트리이기 때문에 사이클이 없다.

weighted graph의 경우 만들어 질 수 있는 spanning tree들 중에 간선
비용의 합이 최소인 것을 MST(minimum spanning tree) 라고 한다.

# Idea

greedy algorithm을 이용한다. 간선들을 모두 모아서 가중치의 오름
차순으로 정렬한다. 정렬된 간선들을 하나씩 탐사 하면서 간선에 연결된
정점의 쌍이 서로 부모가 같지
않다면 [DisjointSet](/doc/disjointset_unionfind.md)에 추가한다.
추가한다. [DisjointSet](/doc/disjointset_unionfind.md)에 추가하면
부모가 같다는 것이고 곧 하나의 트리에 속한다고 볼 수 있다.

예를 들어서 다음과 같은 그래프를 살펴보자.

```
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
             4
```

간선들의 가중치를 `c` 간선의 시작과 끝을 각각 `u, v`라고 할 때
`c u v` 의 모임을 배열 `edges`에 다음과 같이 저장한다.

```
10 0 1
 6 0 2
 5 0 3
10 1 0
15 1 3
 6 2 0
 4 2 3
 5 3 0
15 3 1
 4 3 2
```

`edges` 를 오름 차순으로 정렬 하면 다음과 같다.

```
 4 2 3
 4 3 2
 5 0 3
 5 3 0
 6 2 0
 6 0 2
10 0 1
10 1 0
15 1 3
15 3 1
```

`i`가 0부터 `edges.size()`보다 작을 때 까지 `edges`를 순회 하면서 
다음을 반복한다.


* `c u v`를 얻어 온다. `u`와 `v`가 같은 트리에 속해 있지 않으면 건너
  뛰고 그렇지 않으면 DisjointSet를 이용하여 같은 트리라는 표시를 하고
  `u, v`를 `mst`에 추가한다. `c`는 지금까지 구한 MST 비용의 합에
  더한다.

모든 반복을 마치면 다음과 같은 간선들이 `mst`에 저장된다. 모든 비용의
합은 19이다.

```
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
```

# Keywords

```cpp
vector<pair<int, int> > adj[]
vector<pair<int, pair<int, int> > > edges
DisjointSet ds, vector<pair<int, int> > mst
```

# Implementation

* [c++11](/fundamentals/graph/kruskal/a.cpp)

# Time Complexity

```
O(|E|lg|E|)
```

간선을 정렬하는 시간이 시간복잡도를 지배한다.

# References

* [kruskal algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=71UQH7Pr9kU)
* [Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)](https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/)
