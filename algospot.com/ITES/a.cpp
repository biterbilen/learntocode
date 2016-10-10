// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/CHRISTMAS

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <cstdint>
#include <stack>

int N, K;
const int64_t MOD = 1 << 32;

void print_vector(const std::vector<int>& v) {
  printf("<-- ");
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("-->\n");
}

int64_t get_A(int i) {
  int64_t r   = 1983;

  if (i > 0)
  {
    r = (get_A(i-1) * 214013 + 2531011) % MOD;
  }
  
  return r;
}

int64_t get_input_signal(int i) {
  return get_A(i-1) % 10000 + 1;
}

int solve() {
  return 0;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    //
    scanf("%d", &K);
    scanf("%d", &N);
    //
    printf("%d\n", solve());
  }
  return 0;
}
