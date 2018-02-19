// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/missing-numbers/problem

#include <cstdio>
#include <vector>
#include <algorithm>

int N, M;

std::vector<int> solve(std::vector<int>& ln,
                       std::vector<int>& lm) {
  std::vector<int> r;

  std::sort(ln.begin(), ln.end());
  std::sort(lm.begin(), lm.end());
  
  for (int i = 0; i < ln.size(); ++i) {
    if (ln[i] != lm[i]) {
      // if (i > 0 && lm[i] != lm[i-1])
      r.push_back(lm[i]);
      lm.erase(lm.begin()+i);
    }
  }
  return r;
}

int main() {
  scanf("%d", &N);
  std::vector<int> ln(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &ln[i]);
  scanf("%d", &M);
  std::vector<int> lm(M);
  for (int i = 0; i < M; ++i)
    scanf("%d", &lm[i]);
  std::vector<int> r = solve(ln, lm);
  for (int i = 0; i < r.size(); ++i)
    printf("%d ", r[i]);
  
  return 0;
}

