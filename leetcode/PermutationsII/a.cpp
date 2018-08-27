/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/permutations-ii/description/

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

// 1 1 2
//
// 1 1 2
//
// 1
//
// 2
class Solution {
 public:
  std::set<std::vector<int>> m_r;
  void _solve(std::vector<int>& v) {
    
  }
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    m_r.insert(v);
    _solve(v);
    return std::vector<std::vector<int>>(m_r.begin(), m_r.end());
  }
};

int main() {
  std::vector<int> v = {1, 1, 2};
  
  Solution s;
  auto r = s.permuteUnique(v);

  for (auto rr : r) {
    for (int rrr : rr) {
      printf("%d ", rrr);
    }
    printf("\n");
  }
  
  return 0;
}
