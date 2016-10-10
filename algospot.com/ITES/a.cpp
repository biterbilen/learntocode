// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/CHRISTMAS

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <cstdint>
#include <stack>

int N, K;
const int64_t MOD = 4294967296;//1 << 32;x
int CUR_A_IDX = 0;
int64_t CUR_A_VAL = 1983;
 
int64_t get_next_signal() {
  ++CUR_A_IDX;

  if (CUR_A_IDX > 1)
    CUR_A_VAL = (CUR_A_VAL * 214013 + 2531011) % MOD;
  return CUR_A_VAL % 10000 + 1;
}

int solve() {
  int r = 0;
  int64_t psum = 0;
  std::queue<int64_t> psums;
  
  for (int i = 0; i < N; ++i) {
    // tail을 한 칸 뒤로 이동
    psum += get_next_signal();
    psums.push(psum);
    // psum[head] + k >= psum[tail]을 만족할 때까지 head를 이동
    while (psums.front() + K < psum) {
      psums.pop();
    }
    // 답을 하나 찾은 경우
    if (psums.front() + K == psum)
      ++r;
  }
  return r;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    //
    scanf("%d", &K);
    scanf("%d", &N);
    //
    printf("%d\n", solve());
  }
  return 0;
}


// int main() {
//   for (int i = 0; i < 10; ++i) {
//     printf("%d ", get_next_signal());
//   }
//   return 0;
// }
