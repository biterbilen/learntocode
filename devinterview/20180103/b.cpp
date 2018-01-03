// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/kingdom-division/problem

// Question
// 0. BST?

#include <cstdio>
#include <vector>

int N;
const int MOD = 1000000007;
std::vector<std::vector<int>> adj;

int solve() {
  return 0;
}

int main() {
  scanf("%d", &N);
  adj.resize(N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    adj[a].push_back(b);
  }
  printf("%d\n", solve());

  return 0;
}
