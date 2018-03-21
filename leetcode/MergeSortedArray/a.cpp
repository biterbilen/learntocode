/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

#include <cstdio>
#include <vector>

void print_v(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++ i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

class Solution {
 public:
  void merge(std::vector<int>& nums1, int m,
             std::vector<int>& nums2, int n) {
    if (nums1.back() == 0) {
      nums1.erase(nums1.end()-1);
    }
    
    for (int i = 0; i < m; ++i) {
      while (nums2.size() > 0 && nums1[i] > nums2.front()) {
        nums1.insert(nums1.begin() + i, nums2.front());
        nums2.erase(nums2.begin());
      }
    }
    if (nums2.size() > 0)
      nums1.insert(nums1.end(), nums2.begin(), nums2.end());
  }
};

int main() {
  std::vector<int> v1 = {2, 0};
  std::vector<int> v2 = {1};
  Solution s;
  s.merge(v1, v1.size(), v2, v2.size());
  print_v(v1);
  return 0;
}
