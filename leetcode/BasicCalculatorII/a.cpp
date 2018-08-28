// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/836/

#include <cstdio>
#include <string>
#include <sstream>

//             l
// 0 + 3 + 2 * 2 + 0
//
class Solution {
 public:
  int calculate(std::string s) {
    std::istringstream iss("+"+s+"+");
    int r = 0;     // total
    int last = 0;  // last term
    char opr = 0;  // operator
    int opd = 0;   // operand
    while (iss >> opr) {
      iss >> opd;
      if (opr == '+' || opr == '-') {
        r += last;
        last = (opr == '+' ? opd : -opd);
      } else if (opr == '*') {
        last *= opd;
      } else if (opr == '/') {
        last /= opd;
      }
    }
    return r;
  }
};

int main() {
  std::string a = "3+2*2";
  std::string b = " 3/2";
  std::string c = " 3+5 / 2 ";

  Solution s;
  printf("%d\n", s.calculate(a));
  printf("%d\n", s.calculate(b));
  printf("%d\n", s.calculate(c));
  return 0;
}
