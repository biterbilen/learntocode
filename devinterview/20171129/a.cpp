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
  std::vector<int> m_nums1;
  std::vector<int> m_nums2;
  int _kth(int a, int m, int b, int n, int k) {
    // base condition
    if (m < n)
      return _kth(b, n, a, m, k);
    if (n == 0)
      return m_nums1[k-1];
    if (k == 1)
      return std::min(m_nums1[a], m_nums2[b]);

    // recursion
    int j = std::min(n, k/2);
    int i = k - j;
    if (m_nums1[i-1] > m_nums2[j-1])
      return _kth(a, i, b+j, n-j, k-j);
    return _kth(a-i, m-j, b, j, k-i);
  }
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    m_nums1 = nums1;
    m_nums2 = nums2;
    int cnt1 = nums1.size();
    int cnt2 = nums2.size();
    int k = (cnt1 + cnt2) / 2;
    int m1 = _kth(0, cnt1, 0, cnt2, k + 1);
    if ((cnt1 + cnt2) % 2 == 0) {
      int m2 = _kth(0, cnt1, 0, cnt2, k);
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
