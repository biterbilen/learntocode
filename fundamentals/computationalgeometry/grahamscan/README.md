# Abstract

convex hull algorithm들중 graham scan algorithm에 대해 정리한다.

# Idea

모든 점들을 y값의 오름차순으로 정렬하고 가장 작은 y값을 갖는 점을
p라고 하자. y값이 같은 점이 두개 이상이라면 x값이 가장 작은 점을
p라고 하자. 정렬된 점들을 p와 연결하여 만들어진 선분들의 극각도의
오름차순으로 다시 정렬한다. 정렬된 점들의 첫번째 점은 convex hull이
명백하다.

정렬된 점들의 세번째 점부터 끝점까지 순회하면서 각 점을 c라 하고 c점
마다 다음과 같은 처리를 한다.  c점 보다 정렬 순서가 이른 점을 순서대로
a, b 라고 할때 ccw(a, b, c)가 0보다 작으면 b는 convex hull이 아니다.
만약 b가 convex hull이 아니라면 a를 b로 교체하고 a보다 이전의 점을
a로 교체하여 다시 ccw(a, b, c)가 0보다 작은지 확인한다.

# Implementation

```cpp
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

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
  if (l.y == r.y)
    return l.x < r.y;
  return l.y < r.y;
}

class OrderByPolar {
 public:
  Vector2 p;
  explicit OrderByPolar(Vector2 _p) : p(_p) {}
  bool operator() (const Vector2& a, const Vector2& b) {
    return (a-p).polar() < (b-p).polar();
  }
};

Polygon solve(Polygon& p) {
  int n = p.size();
  Polygon hull;

  // sort p by y order
  std::sort(p.begin(), p.end(), order_by_y);
  // sort p by p[0]-i polar angle
  std::sort(p.begin(), p.end(), OrderByPolar(p[0]));

  hull.push_back(p[0]);
  hull.push_back(p[1]);
  for (int i = 2; i < n; ++i) {
    Vector2 a(0, 0);
    Vector2 b(0, 0);
    do {
      b = hull.back(); hull.pop_back();
      a = hull.back();
    } while (ccw(a, b, p[i]) <= 0);
    hull.push_back(b);
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
```

# Time Complexity

O(NlgN)

# References

* [6. convex hull @ algorithm](https://www.youtube.com/watch?v=-HuIMvYROls&list=PLe-ggMe31CTe_5WhGV0F--7CK8MoRUqBd&index=6)
* [Convex Hull | Set 2 (Graham Scan) @ geeksforgeeks](http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/)
