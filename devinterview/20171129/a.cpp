// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// http://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

// There are two sorted arrays nums1 and nums2 of size m and n
// respectively.

// Find the median of the two sorted arrays. The overall run time
// complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5



// [1, 2, 3]
// [5, 6, 7]
#include <cstdio>
#include <vector>

class Solution {
 public:
  double _kth(const std::vector<int>& nums1, int a, int b,
              const std::vector<int>& nums2, int c, int d, int k) {
    double r;
    return r;
  }
  
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int cnt1 = nums1.size();
    int cnt2 = nums2.size();
    int k = (cnt1 + cnt2) / 2;
    int m1 = _kth(0, cnt1, 0, cnt2, k);
    if ((cnt1 + cnt2) % 2 == 0) {
      int m2 = _kth(0, cnt1, 0, cnt2, k-1);
      return (static_cast<double>(m1) + m2) / 2.0;
    }
    return m1;
  }
};

int main() {
  Solution s;
  std::vector<int> a = {1, 2};
  std::vector<int> b = {3, 4};
  printf("%lf\n", s.findMedianSortedArrays(a, b));
}
