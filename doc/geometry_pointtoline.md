# Abstract

세점이 주어졌을때 한 점과 나머지 두점이 구성하는 직선 사이의 거리를 구해보자.

# Idea

한점을 p라고 하고 직선위의 두점을 a, b라고 하자.
점 p에서 직선의 방향으로 선분을 그어 직선과 수직인 교차점 q를 찾자.
벡터 qp, aq, ap는 다음과 같은 식이 성립한다.

```
qp = ap - aq
```

벡터 aq는 벡터 ap를 벡터 ab에 project한 벡터이다.

결과적으로 벡터 qp의 길이가 점과 직선사이의 거리이다.

혼란하다.

# Implementation

```cpp
#include <cstdio>
#include <cmath>
#include <string>

const double PI = 2.0 * acos(0.0);

struct vector2 {
  double   x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
  bool operator == (const vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  // ???
  bool operator < (const vector2& rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
  vector2 operator + (const vector2& rhs) const {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator - (const vector2& rhs) const {
    return vector2(x - rhs.x, y - rhs.y);
  }
  vector2 operator * (double rhs) const {
    return vector2(x * rhs, y * rhs);
  }
  double norm() const { return hypot(x, y); }
  vector2 normalize() const {
    return vector2(x / norm(), y / norm());
  }
  // angle from x-axis ccw (count clock wise)
  double polar() const {
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }
  double dot(const vector2& rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  double cross(const vector2& rhs) const {
    return x * rhs.y - rhs.x * y;
  }
  // a vector projected to this vector
  vector2 project(const vector2& rhs) const {
    vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
  double howmuchcloser(vector2 p, vector2 a, vector2 b) {
    return (b - p).norm() - (a - p).norm();
  }
  // positive number for ccw b from a
  // negative number for cw b from a
  double ccw(vector2 a, vector2 b) {
    return a.cross(b);
  }
  double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
  }
    
  std::string tostring() const {
    char buf[32] = {0, };
    snprintf(buf, sizeof(buf), "(%0.2lf, %0.2lf)", x, y);
    return buf;
  }
};

vector2 perpendicular_foot(vector2 p, vector2 a, vector2 b) {
  return a + (p - a).project(b - a);
}

double point_to_line(vector2 p, vector2 a, vector2 b) {
  return (p - perpendicular_foot(p, a, b)).norm();
}
```