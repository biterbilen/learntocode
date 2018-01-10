// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <algorithm>

int CACHE[101];
int N;

int solve_recur(const int* w, const int* v, int c) {
  // base condition
  if (c <= 0)
    return 0;

  // memoization
  int& r = CACHE[c];
  if (r != -1)
    return r;

  // recursion
  r = 0;
  for (int i = 0; i < N; ++i) {
    int rr = std::max(v[i] + solve_recur(w, v, c-w[i]),
                 solve_recur(w, v, c));
    r = std::max(r, rr);
  }
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
  N   = 3;

  // for (int i = 0; i < 101; ++i) {
  //   CACHE[i] = -1;
  // }
  // printf("%d\n", solve_recur(W, V, C));  
  printf("%d\n", solve_iter(W, V, C, N));
  // 300
  
  return 0;
}
