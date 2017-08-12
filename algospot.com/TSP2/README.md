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
    _solve_exhaustive_search(path, visited, past_dist + DIST[here][next]);
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

- 지금까지 구한 거리가 이미 BEST보다 크거나 같다면 더이상 search
  space를 탐색할 필요가 없다.

```cpp
  // pruning
  if (BEST <= past_dist)
    return;
```

# simple heuristic pruning



# greedy

# swapping past paths pruning

# MST heuristic pruning

# MST heuristic pruning with memoization
