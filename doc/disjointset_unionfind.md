# Idea

- 교집합이 공집합인 집합들을 disjoint set이라고 한다.
- disjoint set을 구현하기 위해 union find 혹은 merge find(이하 union
  find)에 대해 적는다.
- 서로 다른 두 원소 u와 v가 같은 집합(트리)에 속하는지 판단하거나 두 원소를
  한개의 집합으로 합 할때 사용한다.
- union find는 [kruskal algorithm](graph_kruskal.md)을 구현할때 사용할 수 있다.

# Implementation

- parent[u] 에 u의 부모를 저장하자. 만약 u가 root라면 parent[u] =
  u이다.
- rank[u] 에 u가 포함된 트리의 max level을 저장하자. 이것은 merge에서
  사용된다.
- find(u)는 u가 포함된 트리의 root를 반환 한다. 만약 u의 부모가 u가
  포함된 트리의 root가 아니라면 u의 부모를 u가 포함된 트리의 root로
  교체한다. 이것은 트리의 max level을 가능한 낮게 유지하여 검색 속도를
  향상할 수 있는 좋은 방법이다.
- merge(u, v)는 u, v를 같은 트리에 배치한다. u가 포함된 트리의 root를
  u-root, v가 포함돈 트리의 root를 v-root라고 하자. rank[u-root]와
  rank[v-root]중 큰 녀석이 작은 녀석의 부모가 되도록 하자. 트리의
  level을 낮게 유지하여 검색 속도를 향상할 수 있는 좋은 방법이다. 만약
  rank[u-root]와 rank[v-root]가 같다면 rank[v-root]를 하나만 늘리자.
  v-root가 u-root의 부모가 되기 때문이다.

```cpp
struct DisjointSet {
  std::vector<int> parent, rank;
  explicit DisjointSet(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (rank[u] > rank[v])
      std::swap(u, v);
    // always rank[v] > rank[u] u should be child of v
    parent[u] = v;
    if (rank[u] == rank[v])
      ++rank[v];
  }
};

int main() {
  DisjointSet uf(10);
  uf.merge(0, 5);
  uf.merge(4, 8);
}
```