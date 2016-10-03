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

int get_input_signal(int i) {
  return 0;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    //
    scanf("%d", &K);
    scanf("%d", &N);
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
