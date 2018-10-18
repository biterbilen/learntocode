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
  void solve(std::vector<int>& indices, int beg, int end,
             std::vector<int>& counts, const std::vector<int>& V) {
    int cnt = end - beg;
    if (cnt > 1) {
      // devide
      int step = cnt / 2;
      int mid = beg + step;      
      solve(indices, beg, mid, counts, V);
      solve(indices, mid, end, counts, V);

      // conquer
      std::vector<int> mrgd;
      mrgd.reserve(cnt);
      int idx1 = beg;
      int idx2 = mid;
      int n1 = indices[idx1];
      int n2 = indices[idx2];
      int smallcnt = 0;
      while ((idx1 < mid) || (idx2 < end)) {
        if ((idx2 == end) ||
            ((idx1 < mid) && (V[n1] <= V[n2]))) {
          mrgd.push_back(n1);
          counts[n1] += smallcnt;
          ++idx1;
        } else {
          mrgd.push_back(n2);
          ++smallcnt;
          ++idx2;
        }
      }             
      std::move(mrgd.begin(), mrgd.end(), indices.begin() + beg);
    }
  }
  std::vector<int> countSmaller(std::vector<int>& V) {
    if (V.empty())
      return {};
    int n = V.size();
    std::vector<int> indices(n, 0);
    std::vector<int> counts(n, 0);
    std::iota(indices.begin(), indices.end(), 0);
    solve(indices, 0, n, counts, V);
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
