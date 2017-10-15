// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>
#include <cmath>

int modinv(int a, int M) {
  int r = 1;
  int n = M - 2;
  for (int i = 0; i < n; ++i)
    r *= a % M;
  printf("%d %d : %d\n", a, M, r);
  return r;
}

int solve(const std::vector<int>& num, const std::vector<int>& rem) {
  int n = num.size();
  int prd = 1;
  int r = 0; // result

  for (int i = 0; i < n; ++i)
    prd *= num[i];
  for (int i = 0; i < n; ++i) {
    int pbi = prd / num[i];
    r += rem[i] * modinv(pbi, num[i]) * pbi;
  }

  return r % prd;
}

int main() {
  std::vector<int>num = {3, 4, 5};
  std::vector<int>rem = {2, 3, 1};
  printf("%d\n", solve(num, rem));
  return 0;
}
