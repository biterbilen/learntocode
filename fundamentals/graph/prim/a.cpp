// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <map>

const int MAXI = 987654321;
const int MAXV = 100;
int V = 5;

int prim(int** graph, std::vector<std::pair<int, int>>& mst) {
  int r = 0;
  std::vector<bool> added(V, false);
  std::vector<int> minweight(V, MAXI);
  std::vector<int> parent(V, -1);

  minweight[0] = 0;
  parent[0] = 0;

  for (int i = 0; i < V; ++i) {
    int here = -1;
    for (int j = 0; j < V; ++j) {
      if (!added[j] && (here == -1 || minweight[here] > minweight[j])) {
        here = j;
      }
    }
    // found here with minimum weight
    if (parent[here] != here) {
      mst.emplace_back(parent[here], here);
    }
    r += minweight[here];
    
  }
  
  return r;
}

int main() {
  int graph[V][V] = {{0, 2, 0, 6, 0},
                           {2, 0, 3, 8, 5},
                           {0, 3, 0, 0, 7},
                           {6, 8, 0, 0, 9},
                           {0, 5, 7, 9, 0},};
  std::vector<std::pair<int, int>> mst;
  printf("%d\n", prim(graph, mst));
  return 0;
}

