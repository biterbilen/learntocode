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

int N, K;

void print_vector(const std::vector<int64_t>& psum) {
  printf("<-----");
  for (int i = 0; i < psum.size(); ++i) {
    printf("%lld ", psum[i]);
  }
  printf("----->\n");
}

// D[]의 부분 합 배열 psum[]과 k가 주어질때 몇가지 방법으로 살 수
// 있는지 반환한다.
// psum[]의 첫 번째 원소 전에 0을 삽입했다고 가정한다.
int ways_to_buy(const std::vector<int>& psum, int k) {
  const int MOD = 20091101;
  int r = 0;
  // psum[]의 값을 몇번이나 본적 있는지 기억한다.
  std::vector<int64_t> count(k, 0);
  for (int i = 0; i < psum.size(); ++i) {
    count[psum[i]]++;
  }
  // printf("%d\n", k);
  // print_vector(count);
  // 두번 이상 본 적 있다면 이 값중 두개를 선택하는 방법의 수를
  // 더한다.
  for (int i=0; i < K; ++i) {
    if (count[i] >= 2) {
      r = (r + ((count[i] * (count[i] - 1)) / 2)) % MOD;
    }
  }

  return r;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &K);

    std::vector<int> psum(N, 0);
    for (int i=0; i < N; ++i) {
      int doll_cnt;
      scanf("%d", &doll_cnt);
      if (i > 0) {
        psum[i] += psum[i-1] + doll_cnt;
      } else {
        psum[i] = doll_cnt;
      }
      psum[i] = psum[i] % K;
    }

    // print_psum(psum);
    printf("%d\n", ways_to_buy(psum, K));
  }
  return 0;
}
