# Abstract

이분법(bisection method)에 대해 적는다.

# Idea

특정한 구간 [lo, hi]을 binary search전략으로
탐색해 가는 방법이다.

보통 다음과 같은 형태의 code를 이용한다.

```c
double f(double x);
double bisection(double lo, double hi) {
  if (f(lo) > 0)
    swap(lo, hi)
  for (int i = 0; i < 100; ++i) {
    double mi = (lo + hi) / 2;
    double fmi = f(mi);
    if (fmi <= 0)
      lo = mi;
    else
      hi = mi;
  }
  return (lo + hi) / 2;
}
```

특정한 구간 [lo, hi]의 공역에 해당하는 f(x)는
순증가 혹은 순감소해야 답을 찾을 수 있다.

반복문을 100번 수행하면 bisection()이 return하는 값은
`[lo-hi] / 2^101` 이다. `2^101`은 약 31자리 숫자이다.
`|hi-lo|`가 20자리 미만의 숫자라면 오차는 항상 `10^-7`보다
작게 된다. 그래서 100번 반복한다.