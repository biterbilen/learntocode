// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NERDS2

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;

int main() {
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    std::cin >> N;
    std::vector<int> v_pre_order(N);
    std::vector<int> v_in_order(N);

    int n;
    for (int i = 0; i < N; ++i) {
      std::cin >> v_pre_order[i];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> v_in_order[i];
    }

    print_post_order(v_pre_order, v_in_order);
    std::cout << std::endl;
  }
  //
  return 0;
}
