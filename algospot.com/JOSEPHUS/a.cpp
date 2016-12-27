// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/JOSEPHUS

#include <cstdio>

int N, K;

std::vector<int> Solve() {
  // init q
  std::vector<int> q(N);
  for (int i = 0; i < N; ++i)
    q[i] = i;
  //
  while (q.size() > 2) {
    
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &K);    
    std::vector<int> r = Solve();
    if (r[0] > r[1])
      std::swap(r[0], r[1]);
    printf("%d %d\n", r[0], r[1]);
  }
  
  return 0;
}

