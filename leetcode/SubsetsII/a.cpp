// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/subsets-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 2
//
// 1
// _ 1 2
// _ _ 1 2 2  
// _ 1 2     *
// 2
// _ 2 2
// 2         *
class Solution {
 public:
  std::vector<std::vector<int>> m_r;  // result
  std::vector<int> m_c;  // combination
  std::vector<int> m_v;  // nums
  void solve(int start) {
    // printf("%d | ", start);
    // for (int a : m_c)
    //   printf("%d ", a);
    // printf("\n");
    if (start <= m_v.size()) {
      m_r.push_back(m_c);
    }

    // recursion
    for (int i = start; i < m_v.size(); ++i) {
      if (i > start && m_v[i] == m_v[i-1])
        continue;
      m_c.push_back(m_v[i]);
      solve(i + 1);
      m_c.pop_back();
    }
  }
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    m_v = v;
    solve(0);
    return m_r;
  }
};

int main() {
  std::vector<int> v = {1, 2, 2};

  Solution s;
  auto r = s.subsetsWithDup(v);

  for (auto rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
