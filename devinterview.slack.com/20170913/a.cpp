// Copyright (C) 2017 by iamslash

// Given NxN matrix and degree, then you rotate the matrix data by
// degree.  The value of degree can be plus or minus 90 units.
// (...-360, -270, -180, -90, 0, 90, 180...)  Implement it and say
// timecomplexity and spacecomplexity.

//   ex)
//       matrix :
//           [ 1,  2,  3,  4]
//           [ 5,  6,  7,  8]
//           [ 9, 10, 11, 12]
//           [13, 14, 15, 16]
//       degree : -90
//       output :
//           [ 4,  8, 12, 16]
//           [ 3,  7, 11, 15]
//           [ 2,  6, 10, 14]
//           [ 1,  5,  9, 13]

// g++ -std=c++11 -o a.exe a.cpp

// rot = (angle / 90) % 4
//
// rot: 1, -3
// v[y][x] => v[x][N-y-1]
//
// rot: 2, -2
// v[y][x] => v[N-x-1][N-y-1]
//
// rot, 3, -1
// v[y][x] => v[N-x-1][y]
//
// 0,0 3,0

#include <cstdio>
#include <vector>

int N, A;
std::vector<std::vector<int>> V;

void print_v(const std::vector<std::vector<int>> & v) {
  // print r
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      printf("%d ", v[y][x]);
    }
    printf("\n");
  }
}

void solve(const std::vector<std::vector<int>> & v, int angle) {
  std::vector<std::vector<int>> r = v;
  int rot = (angle / 90) % 4;
  //
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      if (rot == 0) {
        r[y][x] = v[y][x];
      } else if (rot == 1 || rot == -3) {
        r[y][x] = v[x][N-y-1];
      } else if (rot == 2 || rot == -2) {
        r[y][x] = v[N-x-1][N-y-1];
      } else if (rot == 3 || rot == -1) {
        r[y][x] = v[N-x-1][y];
      }
    }
  }
  print_v(r);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &A);
    V = std::vector<std::vector<int>>(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &V[i][j]);
      }
    }
    solve(V, A);
  }
  return 0;
}
