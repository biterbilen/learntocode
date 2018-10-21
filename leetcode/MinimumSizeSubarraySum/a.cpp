// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(int s, const std::vector<int>& nums) {
    if (nums.empty())
      return 0;
    // sliding window
    int l = 0, r = 0, rslt = 0, sum = nums[0];
    while (l <= r && r < nums.size()) {
      if (sum < s) {
        ++r;
      } else if (sum > s) {
        ++l;
      } else {
        rslt = std::min(rslt, r - l);
        ++l;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};

  Solution sln;

  printf("%d\n", sln.minSubArrayLen(7, nums));
  
  return 0;
}
