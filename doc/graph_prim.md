# Abstract

prim algorithm은 MST(minimum spanning tree)를 구하는 알고리즘이다.

spanning tree는 graph에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 트리이기 때문에 사이클이 없다.

weighted graph의 경우 만들어 질 수 있는 spanning tree들 중에 간선
비용의 합이 최소인 것을 MST(minimum spanning tree) 라고 한다.

# Idea

먼저 다음과 같은 자료 구조가 필요하다.

```
vector<pair<int, int> > mst;
// minimum spanning tree를 표현하는 간선의 모임
vector<bool> added;
// added[i] : i번 노드가 mst가 추가되었는지 여부
vector<int> minweight;
// minweight[i] : i번 노드의 인접 노드에서 
// i번 노드까지 도달하는데 필요한 최소 비용
vector<int> parent;
// parent[i] : i번 노드까지 도달하는 최소 비용이 발견 되었을때 
// i번 노드에 도착하는 간선의 시작 노드
```

`added`는 모두 `false`로 초기화 하자. 모든 노드가 `mst`에 포함되지
않았기 때문이다. `minweight`는 아주 큰 값으로 초기화 하자. 아직 모든
노드들에 도달할 최소 비용이 확인이 되지 않았기 때문이다.  `parent`는
아직 최소 비용이 발견되지 않았기 때문에 `-1`로 초기화 하자. `added`와
`mst`는 관련이 있고 `parent`는 `minweight`와 관련이 깊다.

`0`번 노드를 시작으로 MST를 구성해보자.
`mincost[0]`과 `parent[0]`은 `0`으로 초기화 한다. `0`번 노드에서
`0`번 노드까지 비용은 0이기 때문이다.

노드 `i`를 `0`부터 `N - 1` 까지 순회하면서 다음을 반복 한다.

* 아직 방문 하지 않고 `minweight`가 가장 작은 노드를 `u`에 저장한다.
  `u`가 시작노드 `0`일때 간선 `0-0`을 `mst`에 추가하지 않기 위해
  `parent[u]`가 `u`와 같지 않을 때 `parent[u]`와 `u`를 `mst`에
  삽입한다.
* `u`는 `mst`에 추가 된 노드이기 때문에 `added[u]`에 `true`를 저장하고
  `mincost[u]`는 지금까지 구한 MST의 최소 비용에 더한다.
* `u`의 인접 노드들을 탐색하기 위해 `v`를 `0`부터 `N - 1`까지
  순회하면서 다음을 반복한다.
  * `v`가 아직 `mst`에 추가되지 않았고 `u-v`의 비용이 `minweight[v]`보다
    작으면 인접 노드에서 `v`까지 도달하는 최소 비용이 발견되었으므로
    `parent[v]`에 `u`를 저장하고 `minweight[v]`에 간선 `u-v`의 비용을 저장한다.

다음은 `A, B, C, D` 노드가 주어질 때 `A` 노드 부터 시작하여 MST가
만들어지는 과정을 표현한 그림이다.

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
