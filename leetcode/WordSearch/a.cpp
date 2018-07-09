/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/797/

#include <cstdio>
#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::vector<char>> B;
  std::vector<int> dx;
  std::vector<int> dy;
  bool _solve(int y, int x, std::string s) {
    // printf(":%d %d %s\n", y, x, s.c_str());
    // base condition
    if (s.empty())
      return true;
    if (B[y][x] != s[0])
      return false;
    if (s.size() == 1)
      return true;
    printf("%d %d %s\n", y, x, s.c_str());    
    // recursion
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= B.size() ||
            nx < 0 || nx >= B[0].size() || B[ny][nx] < 0)
          continue;
        // printf(" %d %d %s %c %c\n", ny, nx, s.c_str(), B[ny][nx], s[0]);
        int t = B[ny][nx]; B[ny][nx] = -1;
        if (_solve(ny, nx, s.substr(1)))
          return true;
        B[ny][nx] = t;          
    }

    return false;
  }
  bool exist(std::vector<std::vector<char>>& b, std::string s) {
    if (b.size() == 0 || s.empty())
      return false;
    
    // init members
    B = b;
    dy = std::vector<int>{-1, 0, 1, 0};
    dx = std::vector<int>{0, -1, 0, 1};

    //
    for (int i = 0; i < b.size(); ++i) {
      for (int j = 0; j < b[0].size(); ++j) {
        int t = B[i][j]; B[i][j] = -1;
        if (t == s[0] && _solve(i, j, s))
          return true;
        b[i][j] = t;
      }
    }
    // std::reverse(s.begin(), s.end());
    return false;
  }
};

int main() {
  // std::string w = "ABCCED";
  // std::vector<std::vector<char>> b = {
  //   {'A', 'B', 'C', 'E'},
  //   {'S', 'F', 'C', 'S'},
  //   {'A', 'D', 'E', 'E'}
  // };
  // std::string w = "a";
  // std::vector<std::vector<char>> b = {
  //   {'a'}
  // };
  // std::string w = "aaa";
  // std::vector<std::vector<char>> b = {
  //   {'a', 'a'}
  // };
  std::string w = "AAB";
  std::vector<std::vector<char>> b = {
    {'C', 'A', 'A'},
    {'A', 'A', 'A'},
    {'B', 'C', 'D'},
  };
  Solution s;
  printf("%s\n", s.exist(b, w) ? "true" : "false");  
  return 0;
}
