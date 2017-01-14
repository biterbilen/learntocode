// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/ROUTING
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX_INT 987654321

int N, M;

std::vector<std::pair<int, double> > adj[10000];

double Dijkstra(int srcnode) {
  double r = MAX_INT;
  std::vector<double> dist(N, std::numeric_limits<double>::max());
  double srccost = 1.0;
  dist[srcnode] = srccost;
  // -cost, vertex
  std::priority_queue<std::pair<int, double> > pq;
  pq.push(std::make_pair(-srccost, srcnode));
  while (!pq.empty()) {
    int herecost = -pq.top().first;
    int herenode = pq.top().second;
    pq.pop();

    if (dist[herenode] < herecost)
      continue;
    // visit neighbors
    for (int i = 0; i < adj[herenode].size(); ++i) {
      int therenode = adj[herenode][i].first;
      double therecost = herecost * adj[herenode][i].second;
      if (dist[therenode] > therecost) {
        dist[therenode] = therecost;
        pq.push(std::make_pair(-therecost, therenode));
        r = std::min(r, therecost);
        printf("%d %lf %lf\n", therenode, therecost, r);
      }
    }
  }

  return r;
}

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
      double sig;
      scanf("%d %d %lf", &src, &dst, &sig);
      adj[src].push_back(std::make_pair(dst, sig));
      adj[dst].push_back(std::make_pair(src, sig));
    }
    printf("%f\n", Dijkstra(0));
    // printf("%lf\n", std::numeric_limits<double>::max());
    // printf("%f\n", std::numeric_limits<float>::max());
    // printf("%d\n", std::numeric_limits<int>::max());
    // printf("%d\n", std::numeric_limits<short>::max());
    // printf("%d\n", std::numeric_limits<char>::max());
  }

  return 0;
}


