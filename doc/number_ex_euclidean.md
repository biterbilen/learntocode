# Abstract

확장 유클리디안 알고리즘(extended Euclidean algorithm)에 대해 적는다.

# Idea

베주의 정의 (bezout's identity) ax + by = gcd(a, b)의 
(x, y) 를 구하는 방법이다.

```cpp
#include <cstdio>
#include <cstdlib>

int xgcd(int a, int b, int& x, int &y) {
    // baseb condition
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // recursion
    int x1, y1;
    int gcd = xgcd(b, a%b, x1, y1);
    printf("%d = %d * %d + %d * %d\n", gcd, a, x1, b, y1);
    x = y1;
    y = x1 - a/b * y1;

    return gcd;
}

int main() {
    int a = 1020, b = 790;
    int x, y;
    int gcd = xgcd(a, b, x, y);
    printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y);
    return 0;
}
```

```
a = 1020, b = 790

10 = 30 * 1 + 10 * 0
10 = 100 * 0 + 30 * 1
10 = 230 * 1 + 100 * -3
10 = 790 * -3 + 230 * 7
10 = 1020 * 7 + 790 * -24
10 = 1020 * -24 + 790 * 31

gcd(1020, 790)    1020 = 1 x 790 + 230
gcd(790, 230)      790 = 3 x 230 + 100
gcd(230, 100)      230 = 2 x 100 + 30
gcd(100, 30)       100 = 3 x 30 + 10
gcd(30, 10)         30 = 3 x 10 + 0
```

# References

[Basic and Extended Euclidean algorithms @ geeksforgeeks](http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/)
