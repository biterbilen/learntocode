// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MINASTIRITH

#include <cstdio>
#include <map>
#include <vector>

std::vector<std::pair<double, double> > RANGES;
int N;
double Y[100], X[100], R[100];

int solve() {
  int r = 0;
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%lf %lf %lf", &Y[i], &X[i], &R[i]);
    }
    printf("%d\n", solve());
  }
  return 0;
}
