/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combination-sum/description/

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <set>

class Solution {
 public:
  std::set<std::vector<int>> m_s;
  std::vector<int> m_v;
  int m_t;
  // void doit(std::vector<int>& v, int i, int sum) {
  //   // base condition
  //   if (i >= m_v.size() || m_v[i] > m_t)
  //     return;
  //   if (sum + m_v[i] == m_t)
  //     m_rs.insert(v);
  //   // recursion    
  // }
  std::vector<std::vector<int>> combinationSum(
      std::vector<int>& v, int t) {
    m_v = v;
    m_t = t;
    // doit(0);
    return std::vector<std::vector<int>>(m_s.begin(), m_s.end());
        
  }
};

int main() {
  return 0;
}
