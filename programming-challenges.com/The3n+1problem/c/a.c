/* Copyright (C) 2016 by iamslash */

#include <stdio.h>
#include <memory.h>

#define max(a, b) a > b ? a : b;

int CACHE[100000];

int cycle_len(int n) {
  // base condition
  if (n == 1)
    return 1;

  // memoization
  int* r = &CACHE[n];

  // recursion
  if ((*r) < 0) {
    if (n % 2 == 0) {
      *r = 1 + cycle_len(n / 2);
    } else {
      *r = 1 + cycle_len(3 * n + 1);
    }
  }
  //
  return *r;
}

int main() {
  int I, J;
  while (scanf("%d %d", &I, &J) != EOF) {
    memset(CACHE, -1, sizeof(CACHE));
    int m = 0;
    for (int i = I; i <= J; ++i) {
      m = max(m, cycle_len(i));
    }
    printf("%d %d %d\n", I, J, m);
  }

  return 0;
}
