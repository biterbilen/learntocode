// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

class Point {
 public:
  Point(int _x, int _y) : x(_x), y(_y) {}
  int x, y;
};

double solve(const std::vector<Point> v) {
  double r = 0;
  return r;
}

int main() {
  std::vector<Point> v = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  printf("%lf\n", solve(v));
  return 0;
}
