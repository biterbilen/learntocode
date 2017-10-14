# Abstract

확장 유클리디안 알고리즘(extended Euclidean algorithm)에 대해 적는다.

# Idea

베주의 정의 (bezout's identity) ax + by = gcd(a, b)의 
(x, y) 를 구하는 방법이다.

| gcd             | 1st stage          | 2nd stage                                 | val |
|-----------------|:------------------:|------------------------------------------:|:---:|
| gcd(1020, 790)  | 1020 * x + 790 * y | 1020 * -24 +  790 * (7  - 1020/790 * -24) | 10  |
| gcd(790, 230)   |  790 * x + 230 * y |  790 *   7 +  230 * (-3 -  790/230 * 7)   | 10  |
| gcd(230, 100)   |  230 * x + 100 * y |  230 *  -3 +  100 * (1  -  230/100 * -3)  | 10  |
| gcd(100, 30)    |  100 * x +  30 * y |  100 *   1 +   30 * (0  -   100/30 * 1)   | 10  |
| gcd(30, 10)     |   30 * x +  10 * y |   30 *   0 +   10 * (1  -    30/10 * 0)   | 10  |
| gcd(10, 0)      |   10 * x +   0 * y |   10 *   1 +    0 * 0                     | 10  |

위의 표와 같이 1st stage에서 유클리드 알고리즘을 활용하여 gcd(a, b)를
gcd(b, a%b)로 전개해 간다. 마지막행의 gcd(10, 0)이 10이 되려면 x는 1
y는 0이 되어야 한다. 마지막 행까지 전개된 후 2nd stage와 같이 거꾸로
x, y값을 채워 올라간다.

다음은 언급한 알고리즘을 구현한 것이다.

```cpp
#include <cstdio>
#include <cstdlib>

int xgcd(int a, int b, int& x, int &y) {
    // baseb condition
    if (b == 0) {
        x = 1;
        y = 0;
        printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y); 
        return a;
    }

    // recursion
    int x1, y1;
    int gcd = xgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - a/b * y1;
    printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y);
    return gcd;
}

int main() {
    int a = 1020, b = 790;
    int x, y;
    int gcd = xgcd(a, b, x, y);
    return 0;
}
```

다음은 위 코드의 출력 결과이다.

```

10 = 10 * 1 + 0 * 0
10 = 30 * 0 + 10 * 1
10 = 100 * 1 + 30 * -3
10 = 230 * -3 + 100 * 7
10 = 790 * 7 + 230 * -24
10 = 1020 * -24 + 790 * 31
```


# References

[Basic and Extended Euclidean algorithms @ geeksforgeeks](http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/)
