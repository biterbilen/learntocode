// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

// 5 2 6 1
// 
class Solution {
 public:
  std::vector<int> countSmaller(std::vector<int>& V) {
    std::map<int, int> M;  // M[num] = right count
    std::vector<int> rslt(V.size(), 0);
    for (int i = V.size() - 1; i >= 0; --i) {
      int num = V[i];
      auto it = M.lower_bound(num);
      M[num] = (it == M.end()) ? 0 : it->second + 1;
      printf("i: %d k: %d s: %d size: %lu\n", i, num, M[num], M.size());
    }
    for (int i = 0; i < V.size(); ++i) {
      rslt[i] = M[V[i]];
    }
    return rslt;
  }
};


int main() {
  // std::vector<int> V = {5, 2, 6, 1};

  // Solution sln;
  // auto rslt = sln.countSmaller(V);
  // for (int a : rslt) {
  //   printf("%d ", a);
  // }
  // printf("\n");
  // std::map<int, int> M;
  std::vector<int> M = {1, 2, 3};
  auto it = std::lower_bound(M.begin(), M.end(), 5);
  printf("%d\n", it == M.end() ? -1 : *it);
  return 0;
}
