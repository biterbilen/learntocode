// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/MORDOR

#include <cstdio>
#include <cstdlib>
#include <vector>

int N, Q;

struct RMQT {
  void init(const std::vector<int>& v) {
  }
};

void solve(const RMQT& rmqt, int from, int to) {
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &Q);
    std::vector<int> H(N, 0);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &H[i]);
    }
    RMQT rmqt;
    rmqt.init(H);
    // printf("after rmqt.init\n");
    for (int i = 0; i < Q; ++i) {
      int q0, q1;
      scanf("%d %d", &q0, &q1);
      solve(rmqt, q0, q1);
    }
  }
  //
  return 0;
}
