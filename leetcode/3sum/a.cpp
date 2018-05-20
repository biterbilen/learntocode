// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> r;
        int n = nums.size();
      std::sort(nums.begin(), nums.end());
      for (int i = 0; i < n; ++i) {
        if (i != 0 && nums[i-1] == nums[i])
          continue;
        for (int j = i+1; j < n; ++j) {
          if (j != 0 && nums[j-1] == nums[j])
              continue;
          for (int k = j+1; k < n; ++k) {
            if (k != 0 && nums[k-1] == nums[k])
                continue;
            if (nums[i] + nums[j] + nums[k] == 0) {
                std::vector<int> a = {nums[i], nums[j], nums[k]};
                r.push_back(a);
            }
          }
        }
      }
      return r;

    }
};


int main () {
    Solution s;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> r = s.threeSum(nums);
    
    for (auto a : r) {
        printf("[");
        for (int e : a) {
            printf("%d, ", e);
        }
        printf("]\n");
    }

    return 0;
  
}
