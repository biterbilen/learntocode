// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/

#include <cstdio>
#include <vector>


// 0, 1, 2, 0
// 3, 4, 5, 2
// 1, 3, 1, 5

// 0, 0, 0, 0
// 0, 4, 5, 0
// 0, 3, 1, 0

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& M) {
    int m = M.size();
    int n = m > 0 ? M[0].size() : 0;
    if (m == 0 || n == 0)
      return;

    // loop entire lines except top, left lines
    for (int y = 1; y < m; ++y) {
      for (int x = 1; x < n; ++x) {
        if (M[y][0] == 0 || M[0][x] == 0) {
          M[y][x] = 0;
        } else if (M[y][x] == 0) {
          M[y][0] = 0;
          M[0][x] = 0;
        }
      }
    }
    // check whether any element on top line is zero
    for (int x = 0; x < n; ++x) {
      
    }
    // check whether any element on left line is zero

    
  }
};

int main() {
  // [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
  std::vector<std::vector<int>> v = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };

  Solution s;
  s.setZeroes(v);

  // print v
  for (const auto& a : v) {
    for (int b : a) {
      printf("%d, ", b);
    }
    printf("\n");
  }

  return 0;
}
