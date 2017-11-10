# Abstract

convex hull algorithm들중 하나인 gift wrapping algorithm에 대해
정리한다.

# Idea

![](../_img/javis.png)

가장 왼쪽의 점을 p로 정한다. 이 점에서 이 점을 제외한 모든 다른 점들에
선을 그어 선분을 만들었을때 모든 선분들을 반시계 방향으로 갖는 선분
(p, q)를 찾는다. q는 convex hull이다. q를 p로 교체한 후 언급한 과정을
반복한다.

# Implementation

```cpp
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int _x, int _y) {
    x = _x;
    y = _y;
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

bool mycomp(Vector2 l, Vector2 r) {
  if (l.x < r.x) {
    return true;
  } else if (l.x == r.x) {
    return l.y < r.y;
  }
  return false;
}

Polygon solve(const Polygon& p) {
  int n = p.size();
  Polygon hull;

  Vector2 pivot = *std::min_element(p.begin(), p.end(), mycomp);
  hull.push_back(pivot);

  while (true) {
    Vector2 ph = hull.back();
    Vector2 next = p[0];
    for (int i = 1; i < n; ++i) {
      double cross = ccw(ph, next, p[i]);
      double dist = (next - ph).norm() - (p[i] - ph).norm();
      if (cross > 0 || (cross == 0 && dist < 0))
        next = p[i];
    }
    if (next == pivot)
      break;
    hull.push_back(next);
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
```

# Time Complexity

O(NH)

N - 모든 점들의 숫자

H - hull을 구성하는 점들의 숫자

구현은 간단하지만 H가 N과 같다면 O(N^2)이다. Graham scan algorithm -
O(NlgN)이 훨씬 효율적이다.

# References

* [Convex Hull | Set 1 (Jarvis’s Algorithm or Wrapping) @ geeksforgeeks](http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/)
