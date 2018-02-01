# Abstract

교집합이 공집합인 집합들을 상호배타집합(disjoint set)이라고 한다.
union-find 혹은 merge-find 를 이용하여 상호배타집합(disjoint set)을
구현 할 수 있다.  [kruskal algorithm](graph_kruskal.md)에
union-find 를 사용할 수 있다.

# Data Structure Union-Find

임의의 원소 `u`의 부모에 대한 정보를 `vector<int> parent`에
저장한다. 만약 `u`가 root라면 `parent[u] = u` 이다. 

임의의 원소 `u`의 max level에 대한 정보를 `vector<int> rank`에 
저장한다. `rank[u]` 는 `u`가 속한 집합 혹은 트리의 최대 레벨이
담긴다.

# Algorithm Find

## Idea

`find(u)` 는 `u` 가 포함된 트리의 `root`를 반환 한다. 만약 `u` 의
부모가 `u` 가 속한 트리의 root가 아니라면 `u` 의 부모를 `u` 가 포함된
트리의 `root` 로 교체한다. 이것은 트리의 max level을 가능한 낮게
유지하여 검색 속도를 향상할 수 있는 좋은 방법이다. 이것을 path
compression optimization 이라고 한다.

![](/_img/unionfind_find.png)

위의 그림은 `find(0)` 을 수행하기 전과 후이다. 트리의 max level이
낮아 졌음을 확인하자.

## Time Complexity

```
```

# Algorithm Merge

## Idea

`merge(u, v)`는 `u`, `v` 를 같은 트리에 배치한다. `u` 가 포함된 트리의
root를 `u-root`, `v`가 포함된 트리의 root를 `v-root`라고
하자. `rank[u-root]`와 `rank[v-root]`중 큰 녀석이 작은 녀석의 부모가
되도록 하자. 트리의 level을 낮게 유지하여 검색 속도를 향상할 수 있는
좋은 방법이다. 만약 `rank[u-root]`와 `rank[v-root]`가 같다면
`rank[v-root]`를 하나만 늘리자.  `v-root`가 `u-root`의 부모가 되기
때문이다. 이것을 union rank optimization 이라고 한다.

![](/_img/unionfind_merge.png)

위의 그림은 `merge(3, 5)`를 수행하기 전과 후이다. `rank`가 같은 녀석 둘이
결합 하여 `rank`가 하나 증가 했음을 확인하자.

## Time Complexity

# Implementation

[c++11](/fundamentals/disjointset/unionfind/a.cpp)
