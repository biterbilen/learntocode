# Idea

- union find 혹은 merge find에 대해 적는다.

# Implementation

- parent[u] 에 u의 부모를 저장하자. 만약 u가 root라면 parent[u] = u이다.
- rank[u] 에 u가 속한 트리의 max level을 저장하자. 이것은 merge에서 사용된다.
- find(u)는 u의 root를 반환 한다.
- merge(u, v)는 u, v를 같은 트리에 배치한다. 이때 find(u)의 성능을 위해
  트리의 level을 가능한 낮게 유지한다. rank가 큰 root가 rank가 작은
  root의 부모가 되도록한다. 만약 u와 v의 rank가 같다면 v의 rank만 하나
  늘리자. u의 부모가 v이기 때문이다.

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