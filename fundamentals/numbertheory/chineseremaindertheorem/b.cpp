// Copyright (C) 2017 by iamslash

#include <cstdio>

int solve(int num[], int rem[], int k) {
  int r = 1;
  while (true) {
    int j;
    for (j = 0; j < k; ++j) {
      if (r % num[j] != rem[j])
        break;
    }
    if (j == k)
      return r;
    ++r;
  }
  return r;
}

int main() {
  int num[] = {3, 4, 5};
  int rem[] = {2, 3, 1};
  int k = ;
  printf("%d\n", sizeof(num) / sizeof(num[0]));
  printf("%d\n", solve(num, rem, k));
  return 0;
}
