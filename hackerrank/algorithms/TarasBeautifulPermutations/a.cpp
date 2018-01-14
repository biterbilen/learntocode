// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/taras-beautiful-permutations/problem

#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int N;
std::vector<int> A;

// examples
// 1 1 2
//
// 1 1 2 
// 1 2 1
// 1 1 2 .
// 1 2 1
// 2 1 1
// 2 1 1 .

// unique permutation count = n! - 2^(duplicated number count)
int solve() {
  //
  if (N == 1)
    return 1;
  int n_factorial = 1;
  int n_dupnumcnt = 0;
  //
  for (int i = 1; i < N; ++i) {
    n_factorial = n_factorial * (i+1) % MOD;
    if (A[i-1] == A[i])
      ++n_dupnumcnt;
  }
  //
  int a = n_factorial;
  int b = 1 << n_dupnumcnt;
  int c = n_dupnumcnt * (N - 1);
  printf("  %d %d\n", n_factorial, n_dupnumcnt);
  printf("  %d %d %d\n", a, b, c);
  
  return (a / b) - c;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    std::sort(A.begin(), A.end());
    printf("%d\n", solve());
  }
  return 0;
}
