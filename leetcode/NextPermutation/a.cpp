/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/next-permutation/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    
  }
};

int main() {
  std::vector<int> v = {1, 2, 3};

  Solution s;
  s.nextPermutation(v);
  for (int a : v) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
