// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;

struct Vector2
{
  double x, y;

  explicit Vector2(double x = 0, double y = 0) : x(x), y(y) {}

  bool operator == (const Vector2& rhs) const 
  {
    return x == rhs.x && y == rhs.y;
  }

  bool operator < (const Vector2& rhs) const 
  {
    return x != rhs.x? x < rhs.x: y < rhs.y;
  }

  Vector2 operator + (const Vector2& rhs) const 
  {
    return Vector2(x + rhs.x, y + rhs.y);
  }

  Vector2 operator - (const Vector2& rhs) const 
  {
    return Vector2(x - rhs.x, y - rhs.y);
  }

  Vector2 operator * (double rhs) const 
  {
    return Vector2(x * rhs, y * rhs);
  }

  // 벡터의 길이
  double norm() const {return hypot(x, y);}

  Vector2 normalize() const
  {
    return Vector2(x / norm(), y / norm());
  }

  // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
  double polar() const {return fmod(atan2(y, x) + 2 * PI, 2 * PI);}

  // 내적
  double dot(const Vector2& rhs) const
  {
    return x * rhs.x + y * rhs.y;
  }

  // 외적
  double cross(const Vector2& rhs) const
  {
    return x * rhs.y - y * rhs.x;
  }

  // rhs에 사영
  Vector2 project(const Vector2& rhs) const
  {
    Vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
};

typedef std::vector<Vector2> Polygon;
struct Rectangle {
  int x1, y1, x2, y2;
};

double ccw(Vector2 a, Vector2 b) {
  return a.cross(b);
}

double ccw(Vector2 p, Vector2 a, Vector2 b) {
  return ccw(p - a, p - b);
}

// return area of rectangles
int union_area(const vector<Rectangle>& rects) {
  if (rects.empty())
    return 0;

  // event informations
  // x, left or right, number of rectangle
  typedef pair<int, pair<int, int> > Event;
  vector<Event> events;
  vector<int> ys;

  // get y, events
  for (int i=0; i < rects.size(); ++i) {
    ys.push_back(rects[i].y1);
    ys.push_back(rects[i].y2);
    events.push_back(Event(rects[i].x1, make_pair(1, i)));
    events.push_back(Event(rects[i].x2, make_pair(-1, i)));
  }

  // sort ys, remove duplication
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  // sort events
  sort(event.begin(), events.end());
  int r;

  // count[i] = counts of duplicated rectangles between ys[i] and ys[i+1] 
  vector<int> count(ys.size()-1, 0);

  for (int i=0; i < events.size(); ++i) {
    int x = events[i].first;
    int delta = events[i].second.first;
    int rectangle = events[i].second.seond;
    // refresh count
    int y1 = rects[rectangle].y1;
    int y2 = rects[rectangle].y2;
    for (int j=0; i < ys.size(); ++j) {
      if (y1 <= ys[j] && ys[j] < y2) {
        count[j] += delta;
      }
    }
    // get cut_length
    int cut_length = 0;
    for (int j=0; j < ys.size()-1; ++j) {
      if (count[j] > 0) {
        cut_length += ys[j+1] - ys[j];
      }
    }
    // multiply cut_length with distance to next event
    if (i + 1 < events.size()) {
      r += cut_length * (events[i+1].first - x);
    }
  }
  return r;
}

int inter_area(const vector<Rectangle>& rects) {
  return true;
}

bool is_segment_intersected(const Polygon& p) {
  return false;
}


int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
  }

  return 0;
}
