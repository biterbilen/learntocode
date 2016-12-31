// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/CHRISTMAS

#include <cstdio>
#include <vector>

int N, K;

// max counts of one order way
int Solve1(const std::vector<int>& psum) {
  return 0;
}

// max counts of several order ways
// should give away all dolls per one order
int Solve2(const std::vector<int>& psum) {
  return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
      scanf("%d %d", &K, &N);
      std::vector<int> v(N, 0);
      std::vector<int> psum(N+1, 0);
      for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
      }
      // build psum
      psum[0] = v[0];
      for (int i = 1; i < N; ++i) {
        psum[i] = psum[i-1] + v[i];
      }
      psum.insert(psum.begin(), 0);
      printf("%d %d\n", Solve1(psum), Solve2(psum));
    }

  return 0;
}

