// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/divide-two-integers/description/

#include <cstdio>
#include <vector>
#include <limits>

// Time Limit Exceeded
class Solution {
 public:
  int divide(int a, int b) {
    if (b == std::numeric_limits<int>::min())
      return 0;
    if (b == 1)
      return a;
    if (b == -1 && a == std::numeric_limits<int>::min()) {
      return std::numeric_limits<int>::max();
    }
    int rr = 0;
    bool bnegative = false;
    if ((a < 0 && b > 0) ||
        (a > 0 && b < 0))
      bnegative = true;
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
      
    }
    
    return bnegative ? -rr : rr;
  }
};

int main() {
  int a = 10, b = 3;
  // int a = 7, b = -3;
  // int a = 1, b = 1;
  // int a = -2147483648, b = -1;
  // int a = 1004958205, b = -2137325331;
  
  Solution s;
  printf("%d\n", s.divide(a, b));
  return 0;
}
