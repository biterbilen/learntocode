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

    // for (const auto& row : m) {
    //   for (const auto& e : row) {
    //     printf("%d ", e);
    //   }
    //   printf("\n");
    // }
    // traverse
    int sy = 0, ey = ny, sx = 0, ex = nx;  // start y, end y, start x, end x
    int y = 0, x = 0, dy = 0, dx = 1;
    while (sx < ex && sy < ey) {
      printf("%d ", m[y][x]);
      r.push_back(m[y][x]);

      if (y == sy && x == sx)
        sy++, dy = 0, dx = 1;
      else if (x == ex && dy == 0 && dx > 0)
        ex--, dy = 1, dx = 0;
      else if (y == ey && dy > 0 && dx == 0)
        ey--, dy = 0, dx = -1;
      else if (x == sx && dy == 0 && dx < 0)
        sx++, dy = -1, dx = 0;
      y += dy;
      x += dx;
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> m;
  // m.emplace_back(std::vector<int>{1, 2, 3});
  // m.emplace_back(std::vector<int>{3, 4, 5});
  // m.emplace_back(std::vector<int>{6, 7, 8});

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
