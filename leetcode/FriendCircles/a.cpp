/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/846/

#include <cstdio>
#include <vector>


class Solution {
 public:
  std::vector<std::vector<int>> m_M;  // visited
  std::vector<std::vector<int>> m_V;  // visited
  int m_N;
  void dfs(int y, int x) {
    // printf("%d %d\n", y, x);
    m_V[y][x] = 1;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w ||
          m_M[ny][nx] == 0 || m_V[ny][nx] == 1)
        continue;
      dfs(ny, nx);
    }
  }
  int findCircleNum(std::vector<std::vector<int>>& M) {
    if (M.empty() || M[0].empty())
      return 0;
    m_M = M;
    m_V = M;
    m_N = M.size();
    
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        m_V[y][x] = 0;
      }
    }

    int rslt = 0;
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        if (M[y][x] == 0 || m_V[y][x] == 1)
          continue;
          // printf("%d %d\n", y, x);
          dfs(y, x);
          rslt++;
      }
    }
    return rslt;
  }
};

int main() {
  // std::vector<std::vector<int>> M = {
  //   {1, 1, 0},
  //   {1, 1, 0},
  //   {0, 0, 1},
  // };
  // std::vector<std::vector<int>> M = {
  //   {1, 1, 0},
  //   {1, 1, 1},
  //   {0, 1, 1},
  // };
  std::vector<std::vector<int>> M = {
    {1, 0, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 1, 1},
  };
  Solution s;
  printf("%d\n", s.findCircleNum(M));  
  return 0;
}
