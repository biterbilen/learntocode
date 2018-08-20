/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/next-permutation/description/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
 public:
  void nextPermutation(std::vector<int>& v) {
    std::next_permutation(v.begin(), v.end());
  }
};

int main() {
  // std::vector<int> v = {1, 2, 3};
  // std::vector<int> v = {3, 2, 1};
  std::vector<int> v = {1, 1, 5};

  Solution s;
  s.nextPermutation(v);
  for (int a : v) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
