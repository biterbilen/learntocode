// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GRADUATION

#include <cstdio>
#include <vector>

#define MAXINT 987654321

int N, K, M, L;
std::vector<int> req;
std::vector<int> sem;

int CACHE[12][12];

int GetLecCnt(int taken) {
  int r = 0;
  for (int i = 0; i < 12; ++i) {
    if (taken & (1 << i))
      r++;
  }
  return r;
}

// order = this semester order
// taken = taken courses bitmask
int Solve(int order, int taken) {
  // base condition
  if (GetLecCnt(taken) >= K && order < L)
    return 0;
  else if (order >= L)
    return MAXINT;

  // memoization
  int& r = CACHE[order][taken];
  if (r > -1)
    return r;

  // recursion
  for (int subset = sem[order]; subset; subset -= 1) {
    // prerequisited and not taken yet
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init cache
    memset(CACHE, -1, sizeof(CACHE));

    scanf("%d %d %d %d", &N, &K, &M, &L);
    // req[i] = requirement lecture bitmask for lecture i
    req.resize(N, 0);
    sem.resize(M, 0);
    // input for prerequisites
    for (int i = 0; i < N; ++i) {
      int cnt;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        req[i] |= (1 << lecture);
      }
    }
    // input for class
    for (int i = 0; i < M; ++i) {
      int cnt;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        sem[i] |= (1 << lecture);
      }
    }
    int r = Solve(0, 0);
    if (r >= 0) {
      printf("%d\n", r);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
