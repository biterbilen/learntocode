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

std::vector<int> ANS;

void BuildANS(int d, int s, int v) {
  
  if (s < 0 || s > 9 * ((1 << (d+1))-1)) {
    // pruning
    ;
  } else if (s == 0 && d == -1) {
    // base condition
    ANS.push_back(v);
  } else {
    // recursion
    for (int i = 0; i <= 9; ++i)
      BuildANS(d - 1, s - i * (1 << d), v * 10 + i);
  }
}

int64_t decibinaryNumbers(int64_t x) {
    // Complete this function
  return ANS[x-1];
}

int main() {
    int q;

    for (int i = 0; i < 5; ++i)
      BuildANS(20, i, 0);
    for (int i = 0; i < ANS.size(); ++i) {
      printf("%10d\n", ANS[i]);
    }
    
    // cin >> q;
    // for(int a0 = 0; a0 < q; a0++){
    //     int64_t x;
    //     cin >> x;
    //     int64_t result = decibinaryNumbers(x);
    //     cout << result << endl;
    // }
    return 0;
}
