// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/divide-two-integers/description/

#include <cstdio>
#include <vector>
#include <limits>

//
// O(lgN) O(1)
class Solution {
 public:
  int divide(int a, int b) {
    int rr = 0;
    bool bneg = (a < 0) ^ (b < 0);
    if (b < 0) {
      b = -b;
    }
    if (a < 0) {
      if (a == std::numeric_limits<int>::min()) {
        rr = 1;
        a += b;
      }
      a = -a;
    }

    // 
    while (a >= b) {
      int c = b;
      int q = 1;
      while (a >= c) {
        a  -= c;
        rr += q;
        c <<= 1;
        q <<= 1;
        printf("a:%d c:%d rr:%d\n", a, c, rr);
      }
    }
    
    return bneg ? -rr : rr;
  }
};

int main() {
  // int a = 10, b = 3;
  // int a = 7, b = -3;
  // int a = 1, b = 1;
  int a = -2147483648, b = -1;
  // int a = 1004958205, b = -2137325331;
  
  Solution s;
  printf("%d\n", s.divide(a, b));
  return 0;
}
