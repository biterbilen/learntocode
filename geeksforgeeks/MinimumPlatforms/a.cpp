// Copyright (C) 2018 by iamslash


// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

#include <cstdio>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int> > TIME;

int solve() {
  std::sort(TIME.begin(), TIME.end());
  int max = 0;
  int need = 0;
  for (int i = 0; i < TIME.size(); ++i) {
    if (TIME[i].second == 0)
      ++need;
    else
      --need;
    std::max(max, need);
  }
  
  return max;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      int a;
      scanf("%d", &a);
      TIME.emplace_back(a, 0);
    }
    for (int i = 0; i < N; ++i) {
      int b;
      scanf("%d", &b);
      TIME.emplace_back(b, 1);
    }
    printf("%d\n", solve());
  }  
  return 0;
}
