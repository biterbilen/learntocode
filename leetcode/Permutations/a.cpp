/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/795/

#include <cstdio>
#include <vector>

// 1, 2, 3
//
// 1, 2, 3

class Solution {
 public:
  std::vector<std::vector<int>> r;
  std::vector<int> v;
  void _solve(std::vector<int>& nums, int idx) {
    // base condition
    if (idx == nums.size()) {
      r.push_back(v);
      return;
    }

    // recursion
    for (int i = 0; i < nums.size(); ++i) {
      v[idx] = nums[i];
      _solve(nums, idx+1);
    }
  }
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    v = std::vector<int>(nums.size(), 0);
    _solve(nums, 0);
    return r;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3};
  Solution s;
  std::vector<std::vector<int>> r = s.permute(v);
  for (const auto& rr : r) {
    for (int n : rr) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
