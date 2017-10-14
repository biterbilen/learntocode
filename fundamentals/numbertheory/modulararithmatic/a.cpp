#include <cstdio>
#include <cstdlib>

int xgcd(int a, int b, int& x, int &y) {
    // baseb condition
    if (b == 0) {
        x = 1;
        y = 0;
        printf("%d = %d * %d + %d * %d\n", a, a, x, b, y); 
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
    int a = 3, b = 4;
    int x, y;
    int gcd = xgcd(a, b, x, y);
    return 0;
}
