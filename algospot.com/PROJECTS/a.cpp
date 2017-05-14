// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MATCHFIX

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 200
#define MAX_I 987654321

int N, M;
int wins[20];
int match[200][2];

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];


int ford_fulkerson(int source, int sink) {
  int r = 0;

  while (true) {
    std::vector<int> parent(V, -1);
    std::queue<int> q;
    parent[source] = source;
    q.push(source);
    while (!q.empty() && parent[sink] == -1) {
      int here = q.front();
      q.pop();
      for (int there = 0; there < V; ++there) {
        if (capacity[here][there] - flow[here][there] &&
            parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
      }
    }
    // terminate if there is no augmenting path
    if (parent[sink] == -1)
      break;

    int amount = MAX_I;
    for (int p = sink; p != source; p = parent[p]) {
      amount = std::min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    }
    for (int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    r += amount;
  }

  return r;
}


int solve(int from_win) {
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &wins[i]);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &match[i][0], &match[i][1]);
    }

    // init variables
    for (int i = 0; i < MAX_V; ++i) {
      for (int j = 0; j < MAX_V; ++j) {
        capacity[i][j] = 0;
        flow[i][j] = 0;
      }
    }
    V = 2 + M + N;
    printf("%d\n", solve(wins[0]));
  }

  return 0;
}
