/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/810/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<int> V;
  std::vector<int> C;  // C[i]: longest seq cnt of i idx
  int _solve(int a) {
    printf("%d\n", a);
    // base condition
    if (a >= V.size())
      return 0;
    
    // memoization
    int& r = C[a];
    if (r >= 0)
      return r;
    
    // recursion
    r = 0;
    for (int i = 1; i < V.size(); ++i) {
      if (V[a] < V[a+i])
        r = std::max(r, 1 + _solve(a+i));
    }
    return r;
  }
  int lengthOfLIS(std::vector<int>& nums) {
    if (nums.empty())
      return 0;
    else if (nums.size() == 1)
      return 1;
    V = nums;
    C = std::vector<int>(V.size(), -1);
    int r = 0;
    for (int i = 0; i < V.size(); ++i) {
      r = std::max(r, _solve(i));
    }
    return r;
  }
};

int main() {
  // std::vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
  // std::vector<int> v = {0};
  std::vector<int> v = {-2, -1};
  Solution s;
  printf("%d\n", s.lengthOfLIS(v));  
  return 0;
}
