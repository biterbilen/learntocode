// Copyright (C) 2017 by iamslash

// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
// http://mxwell.github.io/draw-graph/?q=digraph

// b.txt 9
// c.txt 45764845

#include <cstdio>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<bool> found;

int cnt;
bool is_cycle = false;

void dfs(int here, int goal) {
  // printf("%d\n", here);
  found[here] = true;

  for (int j = 0; j < adj[here].size(); ++j) {
    int there = adj[here][j];
    if (found[there] == false) {
      dfs(there, goal);
    }
  }

  found[here] = false;
}
    
int main() {
  scanf("%d", &N);
  scanf("%d", &M);
  adj = std::vector<std::vector<int>>(N, std::vector<int>());
  found = std::vector<bool>(N, false);
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    adj[a].push_back(b);
  }
  dfs(0, N-1);
  if (is_cycle)
    printf("INFINITE PATHS");
  else
    printf("%d\n", cnt);
  
  return 0;
}
