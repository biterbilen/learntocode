# Abstract

최대 공약수를 구하는 유클리디안 알고리즘에 대해 적는다.

# Idea

특정 숫자 p와 q의 최대 공약수를 구해보자. p = p'g, q = q'g로
표현하자. p > q이고 g는 공약수이다. 이때 p - q = p'g - q'g, p - q =
g(p' - q')이다. p 와 q의 공약수 g가 있다면 p - q 역시 g가 공약수가
된다.

이번에는 p % q 를 살펴보자.  p % q = p'g % q'g, p % q = g(p' %
q')이다.  p와 q의 공약수 g가 있다면 p % q의 경우 역시 g가 공약수가
된다.

# Implementation

```cpp
int gcd_1(int p, int q) {
  if (p < q)
    std::swap(p, q);
  if (q == 0)
    return p;
  return gcd_1(p - q, q);
}

// p >= q를 위해 swap을 수행할 필요는 없다.
// p < q일때 %연산자에 다음번 호출의
// 경우 p >= q가 보장된다.
int gcd_2(int p, int q) {
  if (q == 0)
    return p;
  return gcd_2(q, p % q);
}
```