// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/

#include <cstdio>
#include <string>


class Solution {
 private:
  std::string _countAndSay(std::string s) {
    std::string r;
    int ccnt = 1;  // count of c
    char c = s[0];
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        ccnt++;
      } else {
        r += '0' + ccnt;
        r += c;
        ccnt = 1;
        c = s[i];
      }
    }
    return r;
  }

 public:
  std::string countAndSay(int n) {
    std::string r = "1";
    for (int i = 0; i < n; ++i) {
      r = _countAndSay(r);
    }
    return r;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.countAndSay(4).c_str());
  return 0;
}
