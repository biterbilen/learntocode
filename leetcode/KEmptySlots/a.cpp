// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/google/67/sql-2/470/

// f[day] = pos
// f[pos] = is_bloom
//    0 1 2
// f: 1 3 2
//    i
// e: 2

// k: 1
//    0 1 2
// f: 1 2 3
//    0 0 0     
// e: 2

#include <cstdio>
#include <vector>

class Solution {
 public:
  int max_cont_empty_cnt(std::vector<char>& g) {
    int r = 0;
    int n = g.size();
    for (int j = 0, c = 0; j < n; ++j) {
      if (g[j] != 0)
        c = 0;
      else
        c++;
      r = std::max(r, c);
    }
    return r;
  }
  int kEmptySlots(std::vector<int>& f, int k) {
    int n = f.size();
    std::vector<char> g(n, 0);
    for (int i = 0; i < n; ++i) {
      g[f[i]-1] = 1;
      if (k == max_cont_empty_cnt(g))
        return i+1;
    }
    return -1;
  }
};

int main() {
  // std::vector<int> f = {1, 3, 2};
  // int k = 1;
  std::vector<int> f = {1, 2, 3};
  int k = 1;
  Solution s;
  printf("%d\n", s.kEmptySlots(f, k));
  return 0;
}
