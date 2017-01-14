// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/NTHLON
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>

int M;
#define VMAX 500
std::vector<std::pair<int, int> > adj[VMAX];

int Dijkstra(const std::vector<int>& a,
             const std::vector<int>& b) {
  int r;
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < VMAX; ++i)
      adj[i].clear();
    scanf("%d", &M);
    std::vector<int> a(M, -1);
    std::vector<int> b(M, -1);

    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &a[i], &b[i]);
      a[i]--;
      b[i]--;
    }

    printf("%d\n", Dijkstra(a, b));
  }

  return 0;
}


