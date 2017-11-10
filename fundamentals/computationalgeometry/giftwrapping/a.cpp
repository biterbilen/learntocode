// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int _x, int _y) : x(_x), y(_y) {}
};

typedef std::vector<Vector2> Polygon;

Polygon solve(const Polygon& p) {
  Polygon r;
  return r;
}

int main() {
  Polygon p = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
               {3, 0}, {0, 0}, {3, 3}};
  
  Polygon r = solve(p);

  for (Vector2 v : r) {
    printf("(%d, %d) ", v.x, v.y);
  }
  printf("\n");
  
  return 0;
}

