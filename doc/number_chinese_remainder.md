# Abstract

중국인 나머지 정리에 대해 적는다.

# Idea

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

## Naive Approcch 

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

## modular multiplicative inverse

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

