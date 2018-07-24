/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/820/

#include <cstdio>
#include <limits>

// when p is INT_MIN
// when q is INT_MIN
class Solution {
public:
  int divide(int p, int q) {
    int rr = 0;
    bool neg = false;
    if ((p > 0 && q < 0) ||
        (p < 0 && q > 0))
      neg = true;
    if (p < 0) {
      p = -p;
    }
    if (q < 0)
      q = -q;    
    while (p >= q) {
      p -= q;
      rr++;
    }
    return neg ? -rr : rr;
  }
};

int main() {
  // int a = 10, b = 3;
  // int a = 7, b = -3;
  int a = -2147483648, b = -1;
  Solution s;
  printf("%d\n", s.divide(a, b));
  
  return 0;
}
