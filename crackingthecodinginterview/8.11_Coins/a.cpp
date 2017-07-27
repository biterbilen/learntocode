// Copyright (C) 2017 by iamslash

// Coins: Given an infinite number of quarters (25 cents), dimes (10
// cents), nickels (5 cents), and pennies (1 cent), write code to
// calculate the number of ways of representing n cents.

#include <cstdio>

int N;
int denoms[4] = {25, 10, 5, 1};
int CACHE[1024][4];

int solve(int n, int idx) {
  // base condition
  if (idx >= 4)
    return 1;
  // memoization
  int& r = CACHE[n][idx];
  if (r != -1)
    return r;
  // recursion
  r = 0;
  for (int i = 0; i * denoms[idx] <= n; ++i) {
    int remain = n - i * denoms[idx];
    r += solve(remain, idx + 1);
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 1024; ++i)
      for (int j = 0; j < 4; ++j)
        CACHE[i][j] = -1;
    scanf("%d", &N);
    printf("%d\n", solve(N, 0));
  }
  return 0;
}

