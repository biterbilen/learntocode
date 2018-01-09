// Copyright (C) 2018 by iamslash
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <cstdio>
#include <algorithm>

int CACHE[101][101];

int solve(const int* w, const int* v, int c, int n) {
  // base condition
  if (n < 0 || c == 0)
    return 0;

  // memoization
  int& r = CACHE[c][n];
  if (r != -1)
    return r;
  
  // recursion
  if (w[n] > c)
    r = solve(w, v, c, n-1);
  else
    r = std::max(v[n-1] + solve(w, v, c-w[n-1], n-1),
                 solve(w, v, c, n-1));
  return r;
}

int solve_iter(const int* w, const int* v, int c, int n) {
  int DP[n+1][c+1];
  // build DP in bottom up style
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= c; ++j) {
      if (i == 0 || j == 0)
        DP[i][j] = 0;
      else if (w[i-1] <= c)
        DP[i][j] = std::max(v[i-1] + DP[i-1][j-w[i-1]], DP[i-1][c]);
      else
        DP[i][j] = DP[i-1][j];
    }
  }
  return DP[n][c];
}

int main() {
  int V[] = {60, 100, 120};
  int W[] = {10, 20, 30};
  int C   = 50;
  int N   = 3;

  for (int i = 0; i < 101; ++i) {
    for (int j = 0; j < 101; ++j) {
      CACHE[i][j] = -1;
    }
  }
  printf("%d\n", solve(W, V, C, N-1));
  // 220
  
  return 0;
}
