// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FENCE

#include <cstdio>
#include <vector>

int N;

// return max square of H[left, right]
int solve(const std::vector<int>& H, int left, int right) {
  int r;
  // base condition
  if (left == right)
    return H[left];
  int mid = (left + right) / 2;
  r = std::max(solve(left, mid), solve(mid+1, right));
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &H[i]);
    }
    printf("%d\n", solve(H, 0, N));
  }

  return 0;
}
