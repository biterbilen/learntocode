// Copyright (C) 2016 by iamslash
// https://leetcode.com/problems/valid-number/
#include <cstdio>
#include <string>

enum STATUS {
  NONE,
  SIGN,
  FIRST_DIGITS,
  DOT,
  E,
  SECOND_DIGITS,
  SECOND_SPACE,
};

class Solution {
 public:
  bool isDigit(const char& c) {
    if (c >= '0' && c <= '9')
      return true;
    return false;
  }

  bool isSpace(const char& c) {
    if (c == ' ' || c == '\t' || c == '\n' ||
        c == '\r' || c == '\v' || c == '\f')
      return true;
    return false;
  }

  bool isSign(const char& c) {
    if (c == '+' || c == '-')
      return true;
    return false;
  }

  // Finite State Machine
  bool isNumber(std::string s) {
    // 0. check space
    // 1. check sign
    // 2. check .
    // 3. check e
    // 4. check digit
    STATUS stat = STATUS::NONE;

    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];

      if (stat == STATUS::NONE) {
        if (isSpace(c)) {
          continue;
        } else if (isSign(c)) {
          stat = STATUS::SIGN;
        } else if (c == '.' || c == 'e') {
          return false;
        } else if (isDigit(c)) {
          stat = STATUS::FIRST_DIGITS;
        } else {
          return false;
        }
      } else if (stat == STATUS::SIGN) {
        if (isDigit(c)) {
          stat = STATUS::FIRST_DIGITS;
        } else {
          return false;
        }
      } else if (stat == STATUS::FIRST_DIGITS) {

      } else if (stat == STATUS::DOT) {
        
      } else if (stat == STATUS::E) {
        
      } else if (stat == STATUS::SECOND_DIGITS) {

      } else if (stat == STATUS::SECOND_SPACE) {
        if (!isSpace(c)) return false;
      }
    }

    return true;
  }
};

int main() {
  Solution s;

  printf("%d\n", s.isNumber("0"));
  printf("%d\n", s.isNumber(" 0.1"));
  printf("%d\n", s.isNumber("abc"));
  printf("%d\n", s.isNumber("1 a"));
  printf("%d\n", s.isNumber("2e10"));

  return 0;
}
