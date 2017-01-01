// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FENCE

#include <cstdio>
#include <stack>
#include <vector>

int N;

int Solve(const std::vector<int>& fence) {
  
  
  
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> fence(N, 0);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &fence[i]);
    }
    fence.insert(fence.begin(), -1);
    fence.push_back(-1);
    printf("%d\n", Solve(fence));
  }

  return 0;
}

