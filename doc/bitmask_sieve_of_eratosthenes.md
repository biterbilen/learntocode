# Abstract

- 에라토스 테네스의 체에 대해 적는다.

# Implementation

- 특정수가 소수다 아니다를 특정 비트가 소수다 아니다로
  표현해보자. 비트들의 배열(SIEVE)이 필요하다. 
- SIEVE는 모두 1로 초기화 하자. 즉 모두 소수다.
- 0과 1은 검증할 필요도 없이 합성수이다.
- i를 2부터 sqrt(n)까지 순회하면서 i의 배수인 녀석(합성수)들을 0으로
  바꾸자. i를 p * q로 표현해보자. 이때 p <= q라고 하자.  그렇다면 p 는
  아무리 커봐야 sqrt(i)를 넘을 수는 없다. 예를 들어서 i를 100이라고
  해보자. p * q (p <= q)형태로 표현할때 p는 아무리 커도 10을 넘을 수
  는 없다.
- i의 배수인 녀석들을 고려할때 i * i부터 시작한다. i는 p * q(p <= q)로
  표현했을때 i * 1은 이미 1 * i에서 고려되엇을 것이다.

```cpp
#define MAX_N 987654321
unsigned char SIEVE[(MAX_N + 7) / 8];

bool is_prime(const int& n) {
  int div = n / 8;
  int mod = n % 8;
  return (SIEVE[div] & (1 << mod)) ? true : false;;
}

// set n as composite number
void set_composite(const int& n) {
  int div = n / 8;
  int mod = n % 8;
  SIEVE[div] &= ~(1 << mod);
}

void eratos_thenes(const int& n) {
  set_composite(0);
  set_composite(1);

  // i = p * q ( p <= q)
  // p <= sqrt(i)
  // j is from i * i to n - 1
  // 
  int sqrtn = sqrt(n);
  for (int i = 2; i < sqrtn; ++i) {
    if (is_prime(i)) {
      printf("  %d\n", i);
      for (int j = i*i; j < n; j+=i) {
        printf("%d ", j);
        set_composite(j);
      }
      printf("\n");
    }
  }
} 
```
