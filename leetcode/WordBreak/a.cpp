// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/word-break/description/

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return false;
  }
};


int main() {
  Solution s;
  std::string a = "leetcode";
  std::vector<std::string> b = {"leet", "code"};
  printf("%d\n", s.wordBreak(a, b));
  return 0;
}
