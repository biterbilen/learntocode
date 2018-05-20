// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

// Time limit exceeded...
// class Solution {
//  public:
//   // {-1, -1, -1, -1, 0, 1, 2, -4}
//   std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
//     std::set<std::vector<int>> s;
//     int n = nums.size();
//     std::sort(nums.begin(), nums.end());
//     for (int i = 0; i < n; ++i) {
//       for (int j = i+1; j < n; ++j) {
//         for (int k = j+1; k < n; ++k) {
//           if (nums[i] + nums[j] + nums[k] == 0) {
//             std::vector<int> a = {nums[i], nums[j], nums[k]};
//             // r.push_back(a);
//             s.insert(a);
//           }
//         }
//       }
//     }
//     std::vector<std::vector<int>> r(s.begin(), s.end());
//     return r;
//   }
// };

class Solution {
 public:
  // {-4, -1, -1, 0, 1, 2}
  //   i,
  //       j,
  //                    k
  
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> r;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        for (int k = j+1; k < n; ++k) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            std::vector<int> a = {nums[i], nums[j], nums[k]};
            // r.push_back(a);
            s.insert(a);
          }
        }
      }
    }
    return r;
  }
};


int main () {
  Solution         s;
  std::vector<int> nums           = {-1, 0, 1, 2, -1, -4};
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
