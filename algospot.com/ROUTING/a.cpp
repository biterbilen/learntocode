// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/ROUTING
#include <cstdio>
#include <vector>
#include <map>

int N, M;

std::vector<std::pair<int, float> > adj[10000];

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 10000; ++i)
      adj[i].clear();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
      int src;
      int dst;
      float sig;
      scanf("%d %d %f", src, dst, sig);
      adj[src].push_back(std::make_pair(dst, sig));
    }
  }

  return 0;
}


