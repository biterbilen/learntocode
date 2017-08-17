// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TSP2

#include <cstdio>
#include <vector>

const double INF = 1e200;
const int MAX = 15;
int N;
double DIST[MAX][MAX];
double BEST;

////////////////////////////////////////////////////////////////////////////////
// swapping past paths pruning
////////////////////////////////////////////////////////////////////////////////

// check last 4 elements of path
// if swapping them past_dist can be shorter???
bool path_swap_prunig(const std::vector<int>& path) {

}

// check sub elements of path except start, end element
// if swapping them past_dist can be shorter???
bool path_reverse_pruning(const std::vector<int>& path) {

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
    _solve_backtracking(path, visited, past_dist + DIST[here][next]);
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

////////////////////////////////////////////////////////////////////////////////
// simple pruning
////////////////////////////////////////////////////////////////////////////////
void _solve_simple_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist)
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_simple_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_simple_pruning() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_simple_pruning(path, visited, 0);
  return BEST;
}

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

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%lf", &DIST[i][j]);
      }
    }
    printf("%lf\n", solve_backtracking());
  }
  return 0;
}
