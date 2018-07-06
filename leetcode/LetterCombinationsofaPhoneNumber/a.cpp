/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/793/

#include <cstdio>
#include <vector>
#include <string>


// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
 public:
  std::vector<std::string> r;
  void _solve(std::vector<std::vector<char>>& n, std::string& d, std::string& c) {
    // printf("%s\n", c.c_str());
    
    // base condition
    if (d.size() == 0) {
      r.push_back(c);
    }
    // recursion
    for (int i = 0, y = d[i]-'2'; i < d.size() && y >= 0 && y <= 7; ++i) {
      for (int x = 0; x < n[y].size(); ++x) {
        char fd = d[0];
        char fc = n[y][x];
        d.erase(0, 1);
        c += fc;
        _solve(n, d, c);
        c.erase(c.size()-1, 1);
        d = fd + d;
      }      
    }
  }
  std::vector<std::string> letterCombinations(std::string d) {
    std::vector<std::vector<char>> n = {{'a','b','c'},
                                        {'d','e','f'},
                                        {'g','h','i'},
                                        {'j','k','l'},
                                        {'m','n','o'},
                                        {'p','q','r', 's'},
                                        {'t','u','v'},
                                        {'w','x','y', 'z'}};
    std::string c;
    _solve(n, d, c);
    return r;
  }
};

int main() {
  std::string a = "23";

  Solution s;
  std::vector<std::string> r = s.letterCombinations(a);
  for (const auto& a : r) {
    printf("%s\n", a.c_str());
  }
  return 0;
}
