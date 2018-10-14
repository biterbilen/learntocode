/* Copyright (C) 2018 by iamslash */
//https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <cstdio>

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int rslt = m;
    for (int i = m+1; i < n; ++i) {
      rslt &= i;
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.rangeBitwiseAnd(5, 7));
  printf("%d\n", sln.rangeBitwiseAnd(0, 1));
  return 0;
}
