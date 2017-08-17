# abstract

- TSP를 해결하는 여러가지 전략들에 대해 적어본다.

# backtracking

- 현재 탐색하는 search space를 탐색하고 그 이전 search space로
  되돌아가서 새로운 search space를 탐색하자.

```cpp
////////////////////////////////////////////////////////////////////////////////
// backtracking
////////////////////////////////////////////////////////////////////////////////
void _solve_backtracking(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_backtracking(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_backtracking() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_backtracking(path, visited, 0);
  return BEST;
}
```

# simple pruning

- 지금까지 구한 거리가 이미 최적해보다 크거나 같다면 더이상 search
  space를 탐색할 필요가 없다.

```cpp
  // pruning
  if (BEST <= past_dist)
    return;
```

# simple heuristic pruning

- heuristic의 범위를 최대한 줄여서 하는 것을 underestimate
  heuristic혹은 optimistic heuristic이라고 한다. heuristic의 범위를
  0으로 하면 극단적으로 좁혀지긴 하지만 heuristic의 대상이 없기 때문에
  가지치기가 되지 않아서 효과가 없다. 그렇다고 heuristic의 범위를 너무
  넓게 하면 최적해 마저 가지치기가 될 수 있다.
- 아직 방문하지 않은 도시들에 대해 인접한 간선중 가장 짧은 간선들의
  합과 지금까지의 거리를 더한 것이 최적해 보다 크다면 가지치기
  하자. 아직 방문하지 않은 도시를 방문 하려면 인접한 간선 중 하나를
  지나가야 하므로 이들 중 가장 짧은 간선의 길이만을 모으면 최단 경로
  이하의 값이 될 수 밖에 없다.

```cpp
////////////////////////////////////////////////////////////////////////////////
// simple heuristic pruning
////////////////////////////////////////////////////////////////////////////////
double MIN_EDGE[MAX];

double simple_heuristic(std::vector<bool>& visited) {
  double r = MIN_EDGE[0];
  for (int i = 0; i < N; ++i) {
    if (!visited[i])
      r += MIN_EDGE[i];    
  }
  return r;
}

void _solve_simple_heuristic_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist + simple_heuristic(visited))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_simple_heuristic_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_simple_pruning() {
  // init heuristic
  for (int i = 0; i < N; ++i) {
    MIN_EDGE[i] = INF;
    for (int j = 0; j < N; ++j) {
      if (i != j)
        MIN_EDGE[i] = std::min(MIN_EDGE[i], dist[i][j]);
    }
  }
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_simple_pruning(path, visited, 0);
  return BEST;
}

```

# greedy

- 가장 가까운 장소부터 탐색하자.

```cpp
////////////////////////////////////////////////////////////////////////////////
// greedy
////////////////////////////////////////////////////////////////////////////////
std::vector<int> NEAREST[MAX];

void _solve_greedy(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  // init NEAREST
  for (int i = 0; i < N; ++i) {
  }
  
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist + simple_heuristic(visited))
    return;
  // recursion
  for (int i = 0; i < NEAREST[here].size(); ++i) {
    int next = NEAREST[here][i];
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_greedy(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_greedy() {
  // init NEAREST
  for (int i = 0; i < N; ++i) {
    std::vector<std::pair<double, int> > order;
    for (int j = 0; j < N; ++j) {
      if (i != j)
        order.push_back(std::make_pair(dist[i][j], j));
    }
    sort(order.begin(), order.end());
    NEAREST[i].clear();
    for (int j = 0; j < order.size(); ++j)
      NEAREST[i].push_back(order[j].second);
  }
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_greedy(path, visited, 0);
  return BEST;
}
```

# swapping past paths pruning

- 지금까지 지나온 경로들중에 순서를 바꿔주면 경로가 짧아지는 경우 더 이상 탐색을
  진행해 봐야 최적해 보다 길이가 커질테니 가지치기 하자. 
  
```cpp
////////////////////////////////////////////////////////////////////////////////
// swapping past paths pruning
////////////////////////////////////////////////////////////////////////////////

// check last 4 elements of path
// if swapping them past_dist can be shorter???
bool path_swap_prunig(const std::vector<int>& path) {
  if (path.size() < 4)
    return false;
  int p = path[path.size() - 4];
  int a = path[path.size() - 3];
  int b = path[path.size() - 2];
  int q = path[path.size() - 1];
  return DIST[p][a] + DIST[b][q] >
      DIST[p][b] + DIST[a][q];
}

// check sub elements of path except start, end element
// if swapping them past_dist can be shorter???
bool path_reverse_pruning(const std::vector<int>& path) {
  if (path.size() < 4)
    return false;
  int b = path[path.size() - 2];
  int q = path[path.size() - 1];
  for (int i = 0; i + 3 < path.size(); ++i) {
    int p = path[i];
    int a = path[i+1];
    if (DIST[p][a] + DIST[b][q] >
      DIST[p][b] + DIST[a][q])
      return true;
  }
  return false;
}

void _solve_swapping_past_paths_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                        int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (path_swap_prunig(path))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_swapping_past_paths_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }  
}

double solve_swapping_past_paths_pruning() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_swapping_past_paths_pruning(path, visited, 0);
  return BEST;
}
```

# MST heuristic pruning

- 현재까지 방문한 거리와 앞으로 방문할 노드들의 MST의 거리를 더한 값이
  지금까지 최적해 보다 작거나 같다면 가지치기 하자.

```cpp
////////////////////////////////////////////////////////////////////////////////
// solve mst heuristic pruning
////////////////////////////////////////////////////////////////////////////////

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
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (rank[u] > rank[v])
      std::swap(u, v);
    // always rank[v] > rank[u] u should be child of v
    parent[u] = v;
    if (rank[u] == rank[v])
      ++rank[v];
    return true;
  }
};

std::vector<std::pair<double, std::pair<int, int> > > EDGES;

double mst_heuristic(int here, const std::vector<bool>& visited) {
  // Kruskal's MST
  DisjointSet sets(N);
  double taken = 0;
  for (int i = 0; i < EDGES.size(); ++i) {
    int a = EDGES[i].second.first;
    int b = EDGES[i].second.second;
    if (a != 0 && a != here && visited[a])
      continue;
    if (b != 0 && b != here && visited[b])
      continue;
    if (sets.merge(a, b))
      taken += EDGES[i].first;
  }
}

void _solve_mst_heuristic_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                        int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST >= past_dist + mst_heuristic(here, visited))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_mst_heuristic_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }   
}

double solve_mst_heuristic_pruning() {
  // init EDGES
  EDGES.clear();
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < i; ++j)
      EDGES.push_back(std::make_pair(DIST[i][j], std::make_pair(i, j)));
  std::sort(EDGES.begin(), EDGES.end());
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_mst_heuristic_pruning(path, visited, 0);
  return BEST;
}
```

# partial dynamic programming

- 앞으로 방문할 노드의 개수가 일정 개수 이하이면 dynamic programming을
  적용하자.
- 부분적으로 dynamic programming을 수행하기 때문에 space를 절약할 수
  있다. 결국 dynamic programming이 제일 빠르다.

```cpp
////////////////////////////////////////////////////////////////////////////////
// solve partial dynamic programming
////////////////////////////////////////////////////////////////////////////////

const int CACHED_DEPTH = 5;
// CACHE[here][remained vertex][visited]
std::map<int, double> CACHE[MAX][CACHED_DEPTH + 1];

double dp(int here, int visited) {
  // base condition
  if (visited == (1 << N) - 1)
    return DIST[here][0];
  // memoization
  int remaining = N - __builtin_popcount(visited);
  double& r = CACHE[here][remaining][visited];
  if (r > 0)
    return r;
  // recursion
  r = INF;
  for (int next = 0; next < N; ++next) {
    if (visited & (1 << next))
      continue;
    r = std::min(r, dp(next, visited + (1 << next))
                 + DIST[here][next]);
  }
  return r;
}

void _solve_partial_dp(std::vector<int>& path,
                                 int& visited, int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (path.size() + CACHED_DEPTH >= N) {
    BEST = std::min(BEST, past_dist + dp(path.back(), visited));
    return;
  }
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited & (1 << next))
      continue;
    visited + (1 << next);
    path.push_back(next);
    _solve_partial_dp(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited - (1 << next);
  }   
}

double solve_partial_dp() {
  // init CACHE
  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j <= CACHED_DEPTH; ++j)
      CACHE[i][j].clear();
  BEST = INF;
  int visited = 1;
  std::vector<int> path(1, 0);
  _solve_partial_dp(path, visited, 0);
  return BEST;
}
```

# Integer Programming

- Integer Programming은 최적화 이론에서 유명한 문제인 Linear
  Programming(선형계획법)의 일종으로 다항시간에 푸는 알고리즘은
  아직 없다. 
