// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/NQUEEN

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

int N;
int BEST = 0;
int64_t END = 0;

void nqueen(int64_t row, int64_t ld, int64_t rd) {
  // base condition
  if (row == END) {
    BEST++;
    return;
  }
  // recursion
  int64_t pos = END & (~(row | ld | rd));
  while (pos != 0) {
    // pick up right most one
    int64_t p = pos & (-pos);
    pos -= p;
    nqueen(row + p, (ld + p) << 1, (rd + p) >> 1);
  }
}

int64_t solve() {
  BEST = 0;
  END = (1 << N) - 1;
  nqueen(0, 0, 0);
  return BEST;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    printf("%lld\n", solve());
  }
}
