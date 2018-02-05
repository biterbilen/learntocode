// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/decibinary-numbers/problem

//   0
//   1
//   2
//  10
//   3
//  11
//   4
//  12
//  20
// 100

// 2^60 = 10^18

#include <bits/stdc++.h>

using namespace std;

long decibinaryNumbers(long x) {
    // Complete this function
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long result = decibinaryNumbers(x);
        cout << result << endl;
    }
    return 0;
}
