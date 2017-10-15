# Abstract

중국인 나머지 정리에 대해 적는다.

# Idea

중국인 나머지 정리의 정의는 다음과 같다.

```
두 양의 정수 m_{1}, m_{2}이 서로소 일때
임의의 두 정수 c_{1}, c_{2}에 대해 연립일차합동방정식
x ≡ c_{1} (mod m_{1})
x ≡ c_{2} (mod m_{2})
는 법 m_{1}, m_{2}에 관하여 단 한개의 해
x ≡ u (mod m1m2)를 갖는다.

x = m_{1} * m_{2} * k + u 이기 때문에
u는 하나 이지만 x는 여러개다.
```

위의 정리를 이용해서 다음과 같은 문제들을 해결 할 수 있다.

```
5로 나누어 나머지가 1이고 7로 나누어 나머지가 3인 수는?
3으로 나누어 나머지가 2, 4로 나누어 나머지가 3, 5로 나누어 나머지가 1인 수는?
```

직관적으로 이해하기 위해 앞서 언급한 문제를 다음과 같이 
해결해 보자.

```
5로 나누어 나머지가 1이고 7로 나누어 나머지가 3인 수는?

x % 5 = 1
x % 7 = 3

x는 31, 66, 101, ...이다.

5 * 7 = 35
x = 31 + 35 * m

3으로 나누어 나머지가 2, 4로 나누어 나머지가 3, 5로 나누어 나머지가 1인 수는?

x % 3 = 2
x % 4 = 3
x % 5 = 1

x는 11, 71, 131, ...이다.

3 * 4 * 5 = 60
x = 11 + 60 * m
```

x를 구하기 위해 무식한 방법(brute force),
나머지 곱셈의 역원(modular multiplicative inverse)을 이용한 방법
등이 있다.

# 무식한 방법 (brute force)

[CRT @ geeksforgeeks](http://www.geeksforgeeks.org/chinese-remainder-theorem-set-1-introduction/)

```
#include <cstdio>

int solve(int num[], int rem[], int k) {
  int r = 1;
  while (true) {
    int j;
    for (j = 0; j < k; ++j) {
      if (r % num[j] != rem[j])
        break;
    }
    if (j == k)
      return r;
    ++r;
  }
  return r;
}

int main() {
  int num[] = {3, 4, 5};
  int rem[] = {2, 3, 1};
  int k = ;
  printf("%d\n", sizeof(num) / sizeof(num[0]));
  printf("%d\n", solve(num, rem, k));
  return 0;
}
```

# 나머지 곱셈의 역원(modular multiplicative inverse)을 이용한 방법



[CRT @ geeksforgeeks](http://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/)
[CRT @ youtube](https://www.youtube.com/watch?v=ru7mWZJlRQg)

```
num[] = {3, 4, 5}    // modular
rem[] = {2, 3, 1}    // remainder
prd[] = 60           // product
pbi[] = {20, 15, 12} // product but i
inv[] = {2,   3,  3} // modular multiplicative inverse of i
  (20 * 2) % 3 = 1
  (15 * 3) % 4 = 1
  (12 * 3) % 4 = 1
  
x = (rem[0]*pbi[0]*inv[0] +
     rem[1]*pbi[1]*inv[1] +
     rem[2]*pbi[2]*inv[2]) % 60
  = (2 * 20 * 2 +
     3 * 15 * 3 +
     1 * 12 * 3) % 60
  = (40 + 135 + 36) % 60
  = 11
```

