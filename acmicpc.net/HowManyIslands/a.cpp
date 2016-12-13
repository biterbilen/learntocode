// Copyright (C) 2016 by iamslash
//
// https://www.acmicpc.net/problem/4963

#include <cstdio>

int M[50][50];

int HowManyIslands(int w, int h) {
  int r = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (M[i][j] == 1)
        ++r;
    }
  }
  return r;
}

int main() {
  int w, h;
  while (scanf("%d %d", &w, &h) != EOF) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        scanf("%d", &M[i][j]);
      }
    }
    printf("%d\n", HowManyIslands(w, h));
  }

  return 0;
}   
