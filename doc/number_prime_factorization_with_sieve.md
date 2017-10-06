# Abstract

소인수분해를 에라토스테네스의 체를 이용하여 수행한다.

# Idea

에라토스테네스의 체를 이용하여 2부터 특정 숫자 n까지 순회 하면서
소인수 분해 했을때 제일 작은 소수를 기록해둔다. 특정 숫자 n을
min_factor를 이용하여 소수들을 모으면 소인수 분해의 구성원이 된다.

# Implementation

```cpp
#define MAX_N 65535

// min_factor[i] : i를 소인수 분해할때 제일 작은 소수
int min_factor[MAX_N];

// sieve of eratosthenes를 이용하여
// 특정 숫자 n까지 순회하면 소인수 분해했을때
// 제일 작은 수를 저장한다.
void eratosthenes(int n) {
  min_factor[0] = min_factor[1] = -1;
  for (int i = 2; i <= n; ++i) {
    min_factor[i] = i;
  }
  int sqrtn = sqrt(n);
  for (int i = 2; i <= sqrtn; ++i) {
    if (min_factor[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (min_factor[j] == j) {
          min_factor[j] = i;
        }
      }
    }
  }
}

vector<int> factor_sieve(int n) {
    vector<int> r;
    while (n > 1) {
      r.push_back(min_factor[n]);
      n /= min_factor[n];
    }
    return r;
}
```
