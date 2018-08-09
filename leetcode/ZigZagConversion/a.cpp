/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/zigzag-conversion/description/

#include <cstdio>
#include <string>
#include <vector>

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//
class Solution {
 public:
  std::string convert(std::string s, int n) {
    if (n == 1)
      return s;
    std::vector<std::string> v(n);
    std::string r;
    int u = n + n / 2; // unit length
    // 
    //
    for (int i = 0; i < s.size(); ++i) {
      int idx  = i % u;
      if (idx >= n) {
        idx = n - (idx - n) - 2;
      }
      v[idx].push_back(s[i]);
      // printf("i: %d, u: %d, idx: %d\n", i, u, idx);
    }

    for (const auto& a : v) {
      r += a;
    }
    return r;
  }
};


// A C D
// B
int main() {
  // std::string ss = "PAYPALISHIRING";
  // int n = 4;
  // std::string ss = "ABCDE";
  // int n = 5;
  std::string ss = "ABCD";
  int n = 2;
  Solution s;
  printf("%s\n", s.convert(ss, n).c_str());
  
  return 0;
}
