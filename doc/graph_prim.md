# Abstract

prim algorithm은 MST(minimum spanning tree)를 구하는 알고리즘이다.

spanning tree는 graph에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 트리이기 때문에 사이클이 없다.

weighted graph의 경우 만들어 질 수 있는 spanning tree들 중에 간선들의
비용의 합이 최소인 것을 MST(minimum spanning tree) 라고 한다.

# Idea

greedy algorithm을 이용한다. MST에 포함된 녀석들의 이웃들중 아직 MST에
포함되지 않은 정점까지의 거리가 가장 최소인 녀석들을 찾아서 MST에
포함한다. MST는 비어 있고 최초 시작점은 그 정점까지 거리가 0이니까
무조건 포함이다.

# Keywords

```cpp
vector<pair<int, int> > adj[],
prim, totalcost, vector<pair<int, int> > mst,
vector<bool> added, vector<int> min_weight, vector<int> parent
```

# Implementation

* [c++11](/fundamentals/graph/prim/a.cpp)

# Time Complexity

```
O(|V|^2+|E|)
```

dense graph인 경우 `|E| = |V|^2`이다. 따라서 시간 복잡도는
`O(|V|^2)`가 될 수 있다. kruskal algorithm은 `O(|E|lg|E|)`이기 때문에
dense graph의 경우 prim algorithm이 더욱 효율적이다.
  
# Space Complexity

- O(1)

# References

* [prim algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=cplfcGZmX7I)
* [Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))](http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/)
