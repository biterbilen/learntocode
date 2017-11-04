// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/POTION

#include <vector>
#include <cmath>

int N;

std::vector<int> solve(const std::vector<int>& R,
                       const std::vector<int>& P) {
  double X = 0.0;
  int Y;
  std::vector<int> A(N);

  for (int i = 0; i < N; ++i) {
    X = fmax(X, static_cast<double>(P[i]) / R[i]);
  }
  Y = ceil(X);

  for (int i = 0; i < N; ++i) {
    A[i] = R[i] * Y - P[i];
  }

  return A;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> R(N);
    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &R[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
    }
    std::vector<int> A = solve(R, P);
    for (int a : A) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}

// int main() {
//   double d = 2 / (double)3;
//   printf("%lf", d);
//   return 0;
// }
