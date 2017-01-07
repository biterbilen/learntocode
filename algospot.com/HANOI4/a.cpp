// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/HANOI4

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <queue>

const int MAX_DISCS = 12;
int C[1 << (MAX_DISCS * 2)];
int N;

int Get(int state, int index) {
  return (state >> (index * 2)) & 3;
}
int Set(int state, int index, int value) {
  return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int Bfs(int disccnt, int begin, int end) {
  if (begin == end)
    return 0;
  std::queue<int> q;
  memset(C, -1, sizeof(C));
  q.push(begin);
  C[begin] = 0;
  while (!q.empty()) {
    int here = q.front();
    q.pop();

    int top[4] = { -1, -1, -1, -1 };
    for (int i = disccnt - 1; i >= 0; --i) {
      top[Get(here, i)] = i;
    }
    for (int i = 0; i < 4; ++i) {
      if (top[i] != -1) {
        for (int j = 0; j < 4; ++j) {
          if (i != j && (top[j] == -1 || top[j] > top[i])) {
            int there = Set(here, top[i], j);
            if (C[there] != -1)
              continue;
            C[there] = C[here] + 1;
            if (there == end)
              return C[there];
            q.push(there);
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    int begin = 0;
    int end = (1 << (N * 2)) - 1;
    for (int i = 0; i < 4; ++i) {
      int O;
      scanf("%d", &O);
      for (int j = 0; j < O; ++j) {
        int P;
        scanf("%d", &P);
        Set(begin, P-1, i);
      }
    }
    printf("%d\n", Bfs(N, begin, end));
  }
  //
  return 0;
}
