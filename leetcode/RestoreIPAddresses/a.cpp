// Copyright (C) 2018 by iamslash
//https://leetcode.com/problems/restore-ip-addresses/description/

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> m_r;
  std::vector<std::string> m_c;
  std::vector<std::string> m_s;
  std::string makeipstr() {
    std::string r;
    for (int i = 0; i < m_c.size(); ++i) {
      r += m_c[i];
      if (i < m_c.size()-1)
        r += ".";
    }
    return r;
  }
  void solve(int start) {
    // base condition
    if (start >= m_s.size()) {
      if (m_c.size() == 4) {
        m_r.push_back(makeipstr());
      }
      return;
    }

    // recursion
    for (int i = start; i < m_s.size();) {
      
    }
  }
  std::vector<std::string> restoreIpAddresses(std::string s) {
    m_s = s;
    solve(0);
    return m_r;
  }
};
