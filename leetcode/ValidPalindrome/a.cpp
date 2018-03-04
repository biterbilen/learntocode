// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    if (s.size() == 0)
      return true;
    auto itend = std::remove(s.begin(), s.end(), ' ');
    s.resize(std::distance(s.begin(), itend));
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.isPalindrome("A man, a plan, a canal: Panama") ?
         "true" : "false");
  return 0;
}
