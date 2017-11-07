// Copyright (C) 2017 by iamslash

#include <vector>

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int a, int b) {
    x = a;
    y = b;
  }
};

bool solve(const std::vector<Vector2>& v, Vector2 p) {
  return true;
}

int main() {
  // {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  // {20, 20}
  std::vector<Vector2> v = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  Vector2 p = {20, 20};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {5, 5};
  printf("%s\n", solve(v, p) ? "true" : "false");

  v = {{0, 0}, {5, 5}, {5, 0}};
  p = {3, 3};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {5, 1};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {8, 1};
  printf("%s\n", solve(v, p) ? "true" : "false");

  v = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  p = {-1, 10};
  printf("%s\n", solve(v, p) ? "true" : "false");

  return 0;
}
