# Abstract

최소 공배수를 구하는 유클리디안 알고리즘에 대해 적는다.

# Idea

특정 숫자 p와 q의 최소 공배수를 구해보자. p는
항상 q보다 크거나 같다.

# Implementation

```cpp
int gcd_1(int p, int q) {
  if (p < q)
    std::swap(p, q);
  if (q == 0)
    return p;
  return gcd_1(p - q, q);
}

int gcd_2(int p, int q) {
  if (q == 0)
    return p;
  return gcd_2(q, p % q);
}
```