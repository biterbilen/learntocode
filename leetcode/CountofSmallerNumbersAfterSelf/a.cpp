// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

// //    i
// // V: 5 2 6 1
// // M: 1 2 6
// // R:   1 1 0
// class Solution {
//  public:
//   std::vector<int> countSmaller(std::vector<int>& V) {
//     if (V.empty())
//       return {};
//     std::vector<int> M;
//     std::vector<int> rslt(V.size(), 0);
//     for (int i = V.size() - 1; i >= 0; --i) {
//       int n = V[i];
//       auto it = std::lower_bound(M.begin(), M.end(), n);
//       rslt[i] = it - M.begin();
//       M.insert(it, n);
//       printf("i: %d, n: %d, R: %d, M.size: %d\n", i, n, rslt[i], M.size());
//     }
//     return rslt;
//   }
// };

class Solution {
 public:
  void solve(std::vector<int>& counts, int l, int r,
             std::vector<int>& result, const std::vector<int>& V) {
  }
  std::vector<int> countSmaller(std::vector<int>& V) {
    if (V.empty())
      return {};
    int n = V.size();
    std::vector<int> counts(n, 0);
    std::vector<int> result(n, 0);
    std::iota(counts.begin(), counts.end(), 0);
    solve(counts, 0, n, result, V);
    return counts;
  }
};

int main() {
  std::vector<int> V = {5, 2, 6, 1};

  Solution sln;
  auto rslt = sln.countSmaller(V);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");

  // std::vector<int> M = {1};
  // auto lit = std::lower_bound(M.begin(), M.end(), 6);
  // auto uit = std::upper_bound(M.begin(), M.end(), 6);
  // printf("begin: %d end: %d e-b: %d lit: %d uit: %d\n",
  //        M.begin(), M.end(), M.end()-M.begin(), lit, uit);
  // printf("*lit: %d, diff: %d\n", *lit, lit-M.begin());
  // printf("*uit: %d, diff: %d\n", *uit, uit-M.begin());
  
  return 0;
}
