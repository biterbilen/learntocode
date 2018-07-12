// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/801/

#include <cstdio>
#include <vector>
#include <limits>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int a = i == 0 ? std::numeric_type<int>::max() : nums[i-1];
      int b = nums[i];
      int c = i == nums.size()-1 ? std::numeric_type<int>::max() : nums[i+1];
      if (a < b && b > c)
        return b;
    }
  }
};

int main() {
  return 0;
}
