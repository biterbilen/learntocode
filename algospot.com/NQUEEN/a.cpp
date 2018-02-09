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
  int i, j;
  // check row on this left side
  for (i = 0; i < y; ++i)
    if (Q[i] == x)
      return false;

  // check upper diagonal on this left side
  for (i = y, j = x; i >= 0 && j >= 0; --i, --j)
    if (Q[i] == j)
      return false;
  
  // check lower diagonal on this left side
  for (i = y, j = x; i < N && j >= 0; ++i, --j)
    if (Q[i] == j)
      return false;
  
  return true;
}

bool nqueen(int y) {
  // base condition
  if (y >= N) {
    BEST++;
    return true;
  }
  
  // recursion
  for (int x = 0; x < N; ++x) {
    if (is_past_ok(y, x)) {
      Q[y] = x;
      if (nqueen(y+1)) {
        return true;
      }
      Q[y] = -1;
    }
  }
  
  return false;
}

long long solve() {
  if (nqueen(0))
    return BEST;
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    memset(Q, -1, sizeof(Q));
    scanf("%d", &N);
    printf("%lld\n", solve());
  }
}
