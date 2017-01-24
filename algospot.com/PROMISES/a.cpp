// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TIMETRIP

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 500
#define MAX_I 987654321

int V, M, N;
int adj[MAX_V][MAX_V];
// int via[MAX_V][MAX_V];

void Floyd() {
  for (int i = 0; i < V; ++i) {
    adj[i][i] = 0;
  }
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
          // via[i][j] = k;
        }
      }
    }
  }
}

bool Update(int a, int b, int c) {
  if (adj[a][b] <= c)
    return false;
  // construct
  for (int x = 0; x < V; ++x) {
    for (int y = 0; y < V; ++y) {
      adj[x][y] = std::min(adj[x][y],
                     std::min(adj[x][a] + c + adj[b][y],
                              adj[x][b] + c + adj[a][y]));
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init adj
    for (int i = 0; i < MAX_V; ++i) {
      for (int j = 0; j < MAX_V; ++j) {
        adj[i][j] = MAX_I;
        // via[i][j] = -1;
      }
    }
    // proc input
    scanf("%d %d %d", &V, &M, &N);
    for (int i = 0; i < M; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      adj[a][b] = c;
      adj[b][a] = c;
    }
    // floyd do it
    Floyd();
    // print result
    int r = 0;
    for (int i = 0; i < N; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      if (Update(a, b, c) == false)
        ++r;
    }
    printf("%d\n", r);
  }
  return 0;
}
