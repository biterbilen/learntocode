// Copyright (C) 2017 by iamslash

#include <cstdio>

int nCr(int n, int r, int p) {
  return 0;
}

int lucas(int n, int r, int p) {
  // base condition
  if (r == 0)
    return 1;

  // recursion
  int ni = n % p;
  int ri = r % p;
  return (lucas(n/p, r/p, p) *
          nCr(n%p, r%p, p)) % p;  
}

int main() {
  int n = 1000;
  int r = 900;
  int p = 13;
  printf("%d\n", lucas(n, r, p));
  return 0;
}
