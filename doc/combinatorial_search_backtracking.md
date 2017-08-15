# abstract

- 완전 탐색의 방법으로 접근할때 새로운 search space를 탐색하고 다시
  이전 search space로 돌아가서 새로운 search space를 탐색하는 방법
- 주로 loop 안에서 recursion하는 형태이다.
- 다음은 [TSP](../algospot.com/TSP2)를 backtracking을 이용하여 해결한 코드이다.

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