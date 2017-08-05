// Copyright (C) 2017 by iamslash

// Boolean Evaluation: Given a boolean expression consisting of the
// symbols 0 (false), 1 (true), & (AND), | (OR), and ^ (XOR), and a
// desired boolean result value result, implement a function to count
// the number of ways of parenthesizing the expression such that it
// evaluates to result. The expression should be fully parenthesized
// (e.g., (0)^(1)) but not extraneously (e.g., (((0))^(1)))
//
// EXAMPLE
// countEval("1^0|0|1", false) -> 2
// countEval("0&0&0&1^1|0", true) -> 10

#include <cstdio>
#include <vector>

std::vector<char> OPERANDS;
std::vector<char> OPERATORS;

// operator_idx : operator index
// result : operation result
// return : profit cases
int solve(int operator_idx, int result) {
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    char buf1[1024];
    char buf2[1024];
    scanf("%s %s", buf1, buf2);
    int n_buf1_len = strlen(buf1);
    for (int i = 0; i < n_buf1_len; ++i) {
      if (i % 2 == 0) {
        OPERANDS.push_back(buf1[i]);
      } else {
        OPERATORS.push_back(buf1[i]);
      }
    }
    printf("%d\n", solve(0, strcmp(buf2, "true") == 0 ? 1 : 0));
  }
  return 0;
}



