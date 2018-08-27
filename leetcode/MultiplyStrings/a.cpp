/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/multiply-strings/description/

#include <cstdio>
#include <string>

// 1 2 3
// 4 5 6
//

class Solution {
 public:
  std::string multiply(std::string a, std::string b) {
    if (a == "0" || b == "0")
      return "0";
    std::vector<int> r;
    for (auto i = b.rbegin(); i != b.rend(); ++i) {
      for (auto j = a.rbegin(); j != a.rend(); ++j) {
        
      }
    }
    std::string rr;
    return rr;
  }
};

int main() {
  std::string a = "123";
  std::string b = "456";
  
  Solution s;
  printf("%s\n", s.multiply(a, b).c_str());
  
  return 0;
}
