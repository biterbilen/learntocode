/* Copyright (C) 2016 by iamslash */

#include <stdio.h>
#define max(a,b)
  ({ __typeof__ (a) _a = (a);
    __typeof__ (b) _b = (b);
    _a > _b ? _a : _b; })

int CACHE[100000];

int cycle_len(int n) {
  return n;
}

int main() {
  int I, J;

  while (scanf("%d %d", &I, &J) != EOF) {
    int max_cycle_len = 0;
    for (int i = I; i <= J; ++i) {
      max_cycle_len = max(max_cycle_len, cycle_len(i));
    }
    printf("%d %d %d\n", I, J, max_cycle_len);
  }

  return 0;
}
