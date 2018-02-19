// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/missing-numbers/problem

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int N, M;

// std::set<int> solve(std::vector<int>& ln,
//                        std::vector<int>& lm) {
//   std::set<int> r;

//   std::sort(ln.begin(), ln.end());
//   std::sort(lm.begin(), lm.end());
  
//   for (int i = 0; i < ln.size(); ++i) {
//     if (ln[i] != lm[i]) {
//       r.insert(lm[i]);
//       lm.erase(lm.begin()+i);
//     }
//   }
//   return r;
// }

// int main() {
//   scanf("%d", &N);
//   std::vector<int> ln(N);
//   for (int i = 0; i < N; ++i)
//     scanf("%d", &ln[i]);
//   scanf("%d", &M);
//   std::vector<int> lm(M);
//   for (int i = 0; i < M; ++i)
//     scanf("%d", &lm[i]);
//   std::set<int> r = solve(ln, lm);
//   for (auto it = r.begin(); it != r.end(); ++it)
//     printf("%d ", *it);
  
//   return 0;
// }

int NS[10001] = {0,};
int MS[10001] = {0,};

int main() {
  int xmax = 0;
  int xmin = 987654321;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    NS[x]++;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    MS[x]++;
    xmin = std::min(xmin, x);
    xmax = std::max(xmax, x);
  }
  for (int i = xmin; i <= xmax; ++i) {
    if (NS[i] != MS[i])
      printf("%d ", i);
  }
  
  return 0;
}


