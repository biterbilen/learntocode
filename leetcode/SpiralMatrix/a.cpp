// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/google/59/array-and-strings/338/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& m) {
    std::vector<int> r;
    // check empty matrix
    int ny = m.size();
    if (ny == 0)
      return r;
    int nx = m[0].size();
    if (nx == 0)
      return r;
    
    // traverse
    int y = 0, x = 1, dy = 0, dx = 1;
    while (true) {
      if (x == nx && dy == 0 && dx > 0)
        dy = 1, dx = 0, nx--;
      else if (y == ny && dy > 0 && dx == 0)
        dy = 0, dx = -1, ny--;
      else if (x == 0 && dy == 0 && dx < 0)
        dy = -1, dx = 0, nx--;
      else if (y == 0 )
    }
    return r;
  }
};

int main() {
  std::vector<std::vector<int>> m = {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 9}};
  Solution s;
  std::vector<int> r = s.spiralOrder(m);
  for (int x : r) {
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}
