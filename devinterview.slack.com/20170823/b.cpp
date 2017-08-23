// Copyright (C) 2017 by iamslash

//
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the
// length is 4.
// Note that there may be more than one LIS combination, it is only
// necessary for you to return the length.

// build : g++ b.cpp -std=c++11 -o b.exe

#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> N = {10, 9, 2, 5, 3, 6, 101, 18};

int CACHE[100][100];

int solve(int cur, int prv) {
  // base condition
  if (cur >= N.size() || N[cur] < N[prv])
    return 0;
  // memoization
  int& r = CACHE[cur][prv];
  if (r != -1)
    return r;
  // recursion
  r = std::max(solve(cur + 1, cur), 1 + solve(cur + 1, cur));
  return r;
}

int main() {
  for (int i = 0; i < 100; ++i)
    for (int j = 0; j < 100; ++j)
      CACHE[i][j] = -1;
  printf("%d\n", solve(0, -1));
  
  return 0;
}
