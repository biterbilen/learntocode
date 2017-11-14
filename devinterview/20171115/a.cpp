// Copyright (C) 2017 by iamslash
// https://www.hackerrank.com/challenges/minimum-loss/problem

// 0 1 2 3
// 7 8 9 1

// 2 1 0 3
// 9 8 7 1

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int N;

void print_v(const std::vector<std::pair<int, int>>& v) {
  for (const std::pair<int, int>& p : v) {
    printf("[%d] %d, ", p.second, p.first);
  }
  printf("\n");
}

int64_t solve(std::vector<std::pair<int, int64_t>>& v) {
  int64_t r = 99999999999999999;

  std::sort(v.begin(), v.end(), std::greater<std::pair<int, int64_t>>());

  // print_v(v);

  for (int i = 0; i < v.size() - 1; ++i) {
    if (v[i].first - v[i+1].first < r) {
      if (v[i].second < v[i+1].second) {
        r = v[i].first - v[i+1].first;
      }
    }
  }

  return r;
}

int main() {
  scanf("%d", &N);
  std::vector<std::pair<int, int64_t>> v;

  for (int i = 0; i < N; ++i) {
    int64_t price;
    scanf("%lld", &price);
    v.emplace_back(std::make_pair(price, i));
  }

  printf("%lld\n", solve(v));

  return 0;
}
