// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/NQUEEN

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

int N;
int Q[12];
long long BEST = 0;

bool is_past_ok(int y, int x) {
  return true;
}

bool is_settable(int y, int x) {
  // base condition
  if (y >= N || x >= N)
    return true;
  
  // recursion
  
  return false;
}

long long solve() {
  
  for (int x = 0; x < N; ++x) {
    is_settable(0, x);
  }
  
  return BEST;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    memset(Q, -1, sizeof(Q));
    scanf("%d", &N);
    printf("%ld\n", solve());
  }
}
