// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <algorithm>

int CACHE[101][101];

int solve_recur(const int* w, const int* v, int c, int n) {
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
    r = std::max(v[n] + solve(w, v, c-w[n], n-1),
                 solve(w, v, c, n-1));
  return r;
}

int solve_iter(const int* w, const int* v, int c, int n) {
  int DP[c+1] = {0,}; // DP[i] = max sum of value of i weight 
  // for (int i = 0; i <= c; ++i) {
  //   DP[i] = 0;
  // }
  // build DP in bottom up style
  // i item is included ???
  for (int i = 0; i <= c; ++i) {
    for (int j = 0; j < n; ++j) {
      if (w[j] <= i)
        DP[i] = std::max(DP[i], v[j] + DP[i-w[j]]);
    }
  }
  return DP[c];
}

int main() {
  int V[] = {10, 30, 20};
  int W[] = {5, 10, 15};
  int C   = 100;
  int N   = 3;

  // for (int i = 0; i < 101; ++i) {
  //   for (int j = 0; j < 101; ++j) {
  //     CACHE[i][j] = -1;
  //   }
  // }
  // printf("%d\n", solve(W, V, C, N-1));
  
  printf("%d\n", solve_iter(W, V, C, N));
  // 300
  
  return 0;
}
