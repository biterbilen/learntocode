// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> m_C;  // cache
  std::vector<std::vector<int>> m_M;  // matrices
  std::vector<std::vector<bool>> m_V;  // visisted
  int m_w;  // width
  int m_h;  // height
  int solve(int y, int x, int cnt) {
    // printf("  y: %d, x: %d\n", y, x);
    m_V[y][x] = true;

    // base condition
    // memoization
    int& rslt = m_C[y][x];
    if (rslt >= 0)
      return rslt;

    // recursion
    cnt++;
    rslt = 0;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w ||
          m_V[ny][nx] || m_M[ny][nx] <= m_M[y][x])
        continue;
      //
      rslt = std::max(cnt, cnt + solve(ny, nx, cnt));
    }
    return rslt;
  }
  int longestIncreasingPath(const std::vector<std::vector<int>>& M) {
    // validate inputs
    if (M.size() == 0 || M[0].size() == 0)
      return 0;
    m_h = M.size();
    m_w = M[0].size();
    m_M = M;
    m_C.resize(m_h, std::vector<int>(m_w, -1));
    int rslt = 0;
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        m_V.resize(m_h, std::vector<bool>(m_w, false));
        rslt = std::max(rslt, solve(y, x, 0));
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> M = {
    {9, 9, 4},
    {6, 6, 8},
    {2, 1, 1}};
  Solution sln;
  printf("%d\n", sln.longestIncreasingPath(M));
  return 0;
}
