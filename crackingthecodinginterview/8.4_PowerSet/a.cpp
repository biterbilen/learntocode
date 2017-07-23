// Copyright (C) 2017 by iamslash

// Power Set: Write a method to return all subsets of a set.

#include <cstdio>
#include <vector>

int N;
std::vector<int> V;

// example : 1 2 3 4 5
std::vector<std::vector<int> > solve(
    const std::vector<std::vector<int> >& v, int idx) {
  std::vector<std::vector<int> > r;

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    V.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &V[i]);
    }
    std::vector<std::vector<int> > v;
    std::vector<std::vector<int> > r = solve(v, 0);
    for (const std::vector& v : r) {
      for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
      printf("\n");
    }
  }
  return 0;
}
