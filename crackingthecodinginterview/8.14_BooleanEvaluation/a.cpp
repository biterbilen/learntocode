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

std::vector<char> OPS;

int CACHE[100][100][2];
// return : profit case count
int solve(int start, int end, int result) {
  printf("%d %d %d\n", start, end, result);
  // base condition
  if (start == end - 1 && (OPS[start] == 0 || OPS[start] == 1)) {
    return OPS[start] == result;
  }
  // memoization
  int& r = CACHE[start][end][result];
  if (r != -1)
    return r;
  // recursion
  r = 0;
  for (int i = start; i <= end; ++i) {
    if (result == 1) {
      switch (OPS[i]) {
      case '&':
        r += solve(start, i, 1) * solve(i + 1, end, 1);
        break;
      case '|':
        r += solve(start, i, 1) * solve(i + 1, end, 1);
        r += solve(start, i, 0) * solve(i + 1, end, 1);
        r += solve(start, i, 1) * solve(i + 1, end, 0);
        break;
      case '^':
        r += solve(start, i, 1) * solve(i + 1, end, 0);
        r += solve(start, i, 0) * solve(i + 1, end, 1);
        break;
      }
    } else {
      switch (OPS[i]) {
      case '&':
        r += solve(start, i, 0) * solve(i + 1, end, 0);
        r += solve(start, i, 1) * solve(i + 1, end, 0);
        r += solve(start, i, 0) * solve(i + 1, end, 1);
        break;
      case '|':
        r += solve(start, i, 0) * solve(i + 1, end, 0);
        break;
      case '^':
        r += solve(start, i, 1) * solve(i + 1, end, 1);
        r += solve(start, i, 0) * solve(i + 1, end, 0);
        break;
      }
    }
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        CACHE[i][j][0] = -1;
        CACHE[i][j][1] = -1;
      }
    }
    char buf1[1024];
    char buf2[1024];
    scanf("%s %s", buf1, buf2);
    int n_buf1_len = strlen(buf1);
    OPS.clear();
    for (int i = 0; i < n_buf1_len; ++i) {
        OPS.push_back(buf1[i]);
    }
    printf("%d\n", solve(0, OPS.size(), strcmp(buf2, "true") == 0 ? 1 : 0));
  }
  return 0;
}



