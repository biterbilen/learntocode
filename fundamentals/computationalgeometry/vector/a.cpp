// Copyright (C) 2017 by iamslash

// cos(x)    = y
// acos(y)   = (x)
// cos(π/2) = 0
// acos(0)   = π/2

#include <cstdio>
#include <cmath>

const double PI = 2.0 * acos(0.0);

struct vector2 {
double   x, y;
explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
    bool operator == (const vector2& rhs) const {
return x == rhs.x && y == rhs.y;
}
        
};


int main() {
  vector2 v;
  return 0;
}
