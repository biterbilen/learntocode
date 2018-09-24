// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/triangle/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// recursive way
// class Solution {
//  public:
//   std::vector<std::vector<int>> m_B;
//   std::vector<std::vector<int>> m_C;
//   int solve(int y, int x, int sum) {
//     // base condition
//     if (y == m_B.size() - 1)
//       return sum + m_B[y][x];

//     // memoization
//     int& r = m_C[y][x];
//     if (r != -1)
//       return r;

//     // recursion
//     r = std::min(solve(y+1, x,   sum + m_B[y][x]),
//                  solve(y+1, x+1, sum + m_B[y][x]));
//     return r;
//   }
//   int minimumTotal(std::vector<std::vector<int>>& B) {
//     if (B.empty())
//       return 0;
//     m_B = B;
//     m_C = B;
//     for (int y = 0; y < B.size(); ++y) {
//       for (int x = 0; x < B[y].size(); ++x) {
//         m_C[y][x] = -1;
//       }
//     }
//     return solve(0, 0, 0);
//   }
// };

// iterative way
// bottom up solution
// O(N^2) O(1)
// 4ms 99.25%
class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& B) {
    if (B.empty())
      return 0;
    for (int i = B.size()-1; i > 0; --i) {
      for (int j = 0; j < B[i].size() - 1; ++j) {
        // printf("%d %d\n", i, j);
        B[i-1][j] += std::min(B[i][j], B[i][j+1]);
      }
    }
    return B[0][0];
  }
};

int main() {
  std::vector<std::vector<int>> B = {
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3},
  };
  Solution s;
  printf("%d\n", s.minimumTotal(B));
  return 0;
}
