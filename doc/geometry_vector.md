# Abstract

벡터클래스를 정의해서 세점중 어느 두점이 가까운지, 내적, 외적등을 구현하자.

# 내적 (dot product)

```latex
\begin{align*}
v \cdot w &= |v||w|\cos\theta
          &= v_{1}w_{1} + v_{2}w_{2}
          
\end{align*}
```

# 외적 (cross product)

```
\begin{align*}
v × w &= |v||w|\sin\theta
      &= v_{1}w_{2} - w_{1}v_{2}
      &= -(w_{1}v_{2} - v_{1}w_{2})
      &= -(w × v)
\end{align*}
```

2D에서 외적의 결과는 두 벡터의 사이각을 의미한다.  예를 들어서 v × w
= r 이라고 하자. (r은 스칼라이다.)  r이 양수이면 w는 v의 ccw 180에
있고 r이 음수이면 w는 v의 cw 180에 있다.

# 극각도 (polar angle)

벡터 a가 x축으로 부터 부터 반시계 방향으로 
회전된 각도이다. atan2를 이용하여 다음과 같이 구한다.
atan2의 값은 [-π, π]이다. 극각도의 범위를 [0, 2π]으로
하기 위해 2π를 더하고 2π로 모듈러 연산 했다.

```cpp
  double polar() const {
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }
```

# 사영된 벡터 (projected vector)

벡터 a가 벡터 b에 사영된 벡터를 구해보자.
벡터 b의 단위 벡터에 벡터 a와 벡터 b의 내적을 곱하자.

```
b_{proj} = a \cdot b \bar{b} 
```

# 가까운 점 (how much closer)

점 p, a, b가 있다. a와 b중 p에 더욱 가까운 것은 무엇일까?
벡터 p-a와 p-b의 크기를 비교하면 알 수 있다.

# Implementation


```cpp
// cos(x)    = y
// acos(y)   = (x)
// cos(π/2) = 0
// acos(0)   = π/2

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


int main() {
  vector2 v(2.0, 3.0);
  printf("%s\n", v.tostring().c_str());
  return 0;
}
```

