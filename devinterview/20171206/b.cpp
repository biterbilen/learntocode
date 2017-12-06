// Copyright (C) 2017 by iamslash

// https://leetcode.com/problems/n-queens-ii/description/
// https://www.hackerrank.com/challenges/queens-on-board/problem

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
 public:
  int m_cnt;
  vector<int> m_rows;

  int valid(int row) {
    if (row == 0)
      return true;
    for (int i = 0; i < row; ++i) {
      if (m_rows[i] == m_rows[row])
        return false;
      if (abs(i - row) == abs(m_rows[i] - m_rows[row]))
        return false;
    }
    return true;
  }
  void solve(int row) {
    // base condition
    if (row == m_rows.size()) {
      ++m_cnt;
      return;
    }
    // recursion
    for (int col = 0; col < m_rows.size(); ++col) {
      m_rows[row] = col;
      if (valid(row))
        solve(row+1);
    }
  }
  int totalNQueens(int n) {
    m_cnt = 0;
    m_rows = vector<int>(n, -1);
    solve(0);
    return m_cnt;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.totalNQueens(10));
  return 0;
}
