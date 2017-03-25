// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/TRAVERSAL

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;

// make slice vector from a to b of v
std::vector<int> slice(const std::vector<int>& v,
                       const std::vector<int>::const_iterator& a,
                       const std::vector<int>::const_iterator& b) {
  if (a == v.end())
    return std::vector<int>();
  return std::vector<int>(a, b);
}

void Solve(const std::vector<int>& p_order, const std::vector<int>& i_order) {
  // base condition
  if (p_order.size() == 0)
    return;

  // recursion
  int root = p_order[0];
  auto it = std::find(i_order.begin(), i_order.end(), root);
  int cnt = it - i_order.begin();

  std::vector<int> p_order_l = slice(p_order, p_order.begin() + 1,
                                     p_order.begin() + cnt);
  std::vector<int> p_order_r = slice(p_order, p_order.begin() + cnt,
                                     p_order.end());
  std::vector<int> i_order_l = slice(i_order, i_order.begin(),
                                     i_order.begin() + cnt);
  std::vector<int> i_order_r = slice(i_order, i_order.begin() + cnt,
                                     i_order.end());

  Solve(p_order_l, i_order_l);
  Solve(p_order_r, i_order_r);
  printf("%d ", root);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
      scanf("%d", &N);
      std::vector<int> p_order(N);
      std::vector<int> i_order(N);
      for (int i = 0; i < N; ++i)
          scanf("%d", &p_order[i]);
      for (int i = 0; i < N; ++i)
          scanf("%d", &i_order[i]);
      Solve(p_order, i_order);
  }
  // std::vector<int> a(10);
  // std::vector<int> b = slice(a, 0, 1);
  // printf("%lu\n", b.size());

  return 0;
}

