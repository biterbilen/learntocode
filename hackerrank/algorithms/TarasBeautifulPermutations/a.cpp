// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/taras-beautiful-permutations/problem

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

const int MOD = 1000000007;
int CACHE[2048][2048]; // CACHE[i][j] = i-th order, j number

int N;
std::vector<int> A;

// examples
// 1 1 2
//
// 1 1 2 X
// 1 2 1 
// 1 1 2 X
// 1 2 1 
// 2 1 1 X
// 2 1 1 X

int solve(const std::set<int> s) {
  if (s.size() == 2)
    return 1;
  int r = 1;
  for (int i = 0; i < s.size(); ++i) {
    r = r * (i+1) % MOD;
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 2000; ++i) {
      for (int j = 0; j < 2000; ++j) {
        CACHE[i][j] = -1;
      }
    }
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    std::sort(A.begin(), A.end());
    // std::erase(std::unique(A.begin(), A.end()), A.end());
    std::set<int> s(A.begin(), A.end());
    printf("%d\n", solve(s));
  }
  return 0;
}
