// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/STRJOIN

#include <cstdio>
#include <vector>
#include <queue>

int N;

std::vector<int> LEN;

int solve() {
  int r = 0;
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    LEN.resize(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &LEN[i]);
    printf("%d\n", solve());
  }
  return 0;
}

