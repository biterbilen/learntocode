// Copyright (C) 2017 by iamslash
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm#Recursive_algorithm

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

// 10 = 30 * 1 + 10 * 0
// 10 = 100 * 0 + 30 * 1
// 10 = 230 * 1 + 100 * -3
// 10 = 790 * -3 + 230 * 7
// 10 = 1020 * 7 + 790 * -24
// 10 = 1020 * -24 + 790 * 31
