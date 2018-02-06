# Abstract

kruskal algorithm은 MST(minimum spanning tree)를 구하는 알고리즘이다.

spanning tree는 graph에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 트리이기 때문에 사이클이 없다.

weighted graph의 경우 만들어 질 수 있는 spanning tree들 중에 간선들의
비용의 합이 최소인 것을 MST(minimum spanning tree) 라고 한다.

# Idea

greedy algorithm을 이용한다. 간선들을 모두 모아서 가중치의 오름
차순으로 정렬한다. 정렬된 간선들을 하나씩 탐사 하면서 간선에 연결된
정점의 쌍이 서로 부모가 같지
않다면 [DisjointSet](/doc/disjointset_unionfind.md)에 추가한다.
추가한다. [DisjointSet](/doc/disjointset_unionfind.md)에 추가하면
부모가 같다는 것이고 곧 하나의 트리에 속한다고 볼 수 있다.

# Keywords

```cpp
vector<pair<int, int> > adj[], DisjointSet,
kruskal, int totalcost, vector<pair<int, int> > mst,
vector<pair<int, pair<int, int> > > edges
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
