# Abstract

1과 자신을 제외한 숫자로 나누어 떨어지지 않는 숫자를
소수(prime number)라고 한다.

# Idea

어떤 숫자 n이 주어졌을때 소수인지 합성수인지 구별해 보자.  0과 1은
소수가 아니다. n이 2가 아니고 짝수라면 소수가 아니다. n을 p x q로
표현해 보자. 이때 p < q 이다. p를 3부터 시작해서 특정 홀수까지 반복한
숫자들로 n을 나눌 수 있다면 n은 소수가 아니다. p가 만약 q보다 크거나
같다면 이미 반복한 숫자이기 때문에 p < q 경우만 생각해도 된다. 따라서
n이 n의 제곱근 s를 얻어서 3부터 s보다 작거나 같은 홀수들로 나누어
떨어진다면 소수가 아니다.

# Implementation

```cpp
bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  int sqrtn = sqrt(n);
  for (int i = 3; i <= sqrtn; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}
```
