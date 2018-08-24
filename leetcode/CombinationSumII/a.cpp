/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combination-sum-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 2 2 5
class Solution {
 public:
  std::vector<std::vector<int>> m_r;
  void _combi(std::vector<int>& candi, int t,
              std::vector<int>& combi, int sum, int idx) {
    printf("idx:%d sum:%d comb: ", idx, sum);
    for (int i = 0; i < combi.size(); ++i)
      printf("%d ", combi[i]);
    printf("\n");
    // base condition
    if (idx >= candi.size())
      return;
    // if (sum + candi[idx] > t)
    //   return;
    if (sum + candi[idx] == t) {
      m_r.push_back(combi);
      // combi.clear();
      return;
    }

    // recursion
    for (int i = idx; i < candi.size(); ++i) {
      // if (i > 0 && candi[i] == candi[i-1])
      //   continue;
      combi.push_back(candi[i]);
      _combi(candi, t, combi, sum + candi[i], i+1);
      combi.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candi, int t) {
    std::sort(candi.begin(), candi.end());
    std::vector<int> combi;
    _combi(candi, t, combi, 0, 0);
    return m_r;
  }
};

int main() {

  std::vector<int> v = {2, 5, 2, 1, 2};
  int t = 5;
  
  Solution s;
  auto r = s.combinationSum2(v, t);

  for (auto rr : r) {
    for (int b : rr) {
      printf("%d\n", b);
    }
    printf("\n");
  }
  
  return 0;
}
