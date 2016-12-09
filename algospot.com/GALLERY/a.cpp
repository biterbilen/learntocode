// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GALLERY

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

const int MAX_V = 1000;

int G, H;
int V;
std::vector<int> adj[MAX_V];

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &G);
    scanf("%d", &H);

    for (int i = 0; i < G; ++i) {
      for (int j = 0; j < G; ++j) {
        adj[i][j] = 0;
      }
    }

    for (int i = 0; i < H; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      adj[x][y] = 1;
    }

    // printf("%s\n", solve(words).c_str());
  }
  //
  return 0;
}
