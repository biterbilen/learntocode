// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/GENIUS

#include <cstdio>
#include <vector>

int N, K, M;        // 플레이어에 들어 있는 곡수, K분 30초, 태윤이가 좋아하는 고수
double TRANS[50][50];      // T[i][j] : i가 재생된후 j가 재생될 확률
std::vector<int> L; // 곡의 길이
std::vector<int> Q; // 곡의 번호
std::vector<double> P; // 태윤이가 좋아하는 곡이 재생되고 있을 확률

// rule
// 모든 곡들의 길이는 모두 1, 2, 3, 4분

// min후에 cur노래가 시작될 확률
doulbe solve(int min, int cur) {
  // base condition
  if (rmn_min <= 0)
    return 0;
  // memoization
  // recursion
  double r = 0.0;
  for (int i = 0; i < N; ++i) {
    r += solve(i, rmn_min - L[i]) * TRANS[i][cur_idx];
  }

  return r;
}

int main() {

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d %d", &N, &K, &M);
    L.resize(N);
    Q.resize(M);
    P.resize(M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &L[i]);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%f", &TRANS[i][j]);
      }
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d", &Q[i]);
    }
    for (int i = 0; i < M; ++i) {
      printf("%0.8f ", solve(Q[i], K));
    }
    printf("\n");
  }
  
  return 0;
}

