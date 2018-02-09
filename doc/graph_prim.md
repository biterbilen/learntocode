# Abstract

prim algorithm은 MST(minimum spanning tree)를 구하는 알고리즘이다.

spanning tree는 graph에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 트리이기 때문에 사이클이 없다.

weighted graph의 경우 만들어 질 수 있는 spanning tree들 중에 간선들의
비용의 합이 최소인 것을 MST(minimum spanning tree) 라고 한다.

# Idea

greedy algorithm을 이용한다. 아래 Keywords에 해당하는 자료구조가
필요하다. `mst`는 스패닝 트리를 구성할 간선이 저장되어 있다.  `mst`에
아직 삽입되지 않는 노드중에 `minweight[u]`가 가장 작은 노드 `u`를
찾아내서 `mst`에 삽입하자. 삽입된 노드 `u`는 `added[u]` 를 `true`로
변경한다.  노드 `u`의 이웃들을 탐색한다. 이때 탐색하는 이웃 노드를
`v`라고 하자. `minweight[v]`는 어디서 부터인지는 모르겠지만 `v`노드
까지 오는데 최소의 비용이 저장되어 있다. 초기 값은 아주 큰값을
저장한다.  `u`에서 `v`까지 비용이 `minweight[v]`보다 작으면 새로운
최소 비용이므로 `minweight[v]`를 갱신한다. 갱신된 `v`노드에 대하여
`parent[v]`를 `u`로 변경한다.

`mst`와 `added`는 서로 관련이 깊다. `minweight`와 `parent`는 역시 서로
관련이 깊다.

![](/_img/prim.png)

# Keywords

```cpp
vector<pair<int, int> > adj[],
vector<pair<int, int> > mst, vector<bool> added, 
vector<int> minweight, vector<int> parent
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
