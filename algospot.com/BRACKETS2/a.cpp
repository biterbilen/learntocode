// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/CHRISTMAS

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <cstdint>
#include <stack>

int N, K;

void print_vector(const std::vector<int>& v) {
  printf("<-- ");
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("-->\n");
}

bool is_closed(const std::string& brackets) {
  // printf("> %lu \n", brackets.size());
  std::stack<char> bstack;
  for (int i = 0; i < brackets.size(); ++i) {
    char c = brackets[i];
    if (c == '(' || c == '{' || c == '[') {
      bstack.push(c);
    } else if (c == ')') {
      if (bstack.size() == 0)
        return false;
      else if (bstack.top() == '(')
        bstack.pop();
    } else if (c == '}') {
      if (bstack.size() == 0)
        return false;
      else if (bstack.top() == '{')
        bstack.pop();
    } else if (c == ']') {
      if (bstack.size() == 0)
        return false;
      else if (bstack.top() == '[')
        bstack.pop();
    } else {
      break;
    }
  }
  if (bstack.size() > 0)
    return false;
  return true;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    char buf[10000] = {0, };
    //
    scanf("%s", buf);
    //
    std::string brackets = buf;
    //
    if (is_closed(brackets))
      printf("YES");
    else
      printf("NO");
    printf("\n");
  }
  return 0;
}
