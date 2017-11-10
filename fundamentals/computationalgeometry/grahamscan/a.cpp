// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const double PI = 2.0 * acos(0.0);

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int _x, int _y) {
    x = _x;
    y = _y;
  }
  Vector2& operator = (const Vector2& rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
  bool operator == (const Vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  Vector2 operator + (const Vector2& rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
  }
  Vector2 operator * (double rhs) const {
    return Vector2(x * rhs, y * rhs);
  }
  Vector2 operator - (const Vector2& rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
  }
  double cross(const Vector2& rhs) const {
    return x * rhs.y - rhs.x * y;
  }
  double norm() const { return hypot(x, y); }
  // angle from x-axis ccw (count clock wise)
  double polar() const {
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }
};

// positive number for ccw b from a
// negative number for cw b from a
double ccw(Vector2 a, Vector2 b) {
  return a.cross(b);
}

double ccw(Vector2 p, Vector2 a, Vector2 b) {
  return ccw(a-p, b-p);
}

typedef std::vector<Vector2> Polygon;

bool order_by_y(const Vector2& l, const Vector2& r) {
  return l.y < r.y;
}

class OrderByPolar {
 public:
  Vector2 p;
  explicit OrderByPolar(Vector2 _p) : p(_p) {}
  bool operator() (Vector2 a, Vector2 b) {
    return (a-p).polar() < (b-p).polar();
  }
};

Polygon solve(const Polygon& p) {
  int n = p.size();
  Polygon hull;

  // sort p by y order
  std::sort(p.begin(), p.end(), order_by_y);
  // sort p by p[0]-i polar angle
  // OrderByPolar comp(p[0]);
  // std::sort(p.begin(), p.end(), comp);

  hull.push_back(p[0]);
  hull.push_back(p[1]);
  for (int i = 2; i < n; ++i) {
    Vector2 top = hull.back(); hull.pop_back();
    Vector2 no2 = hull.back();
    while (ccw(top, no2, p[i]) <= 0) {
      top = hull.back();
      hull.pop_back();
    }
    hull.push_back(top);
    hull.push_back(p[i]);
  }

  return hull;
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
