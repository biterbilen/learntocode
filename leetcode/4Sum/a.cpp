/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/4sum/description/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& v, int t) {
    std::vector<std::vector<int>> r;
    std::set<int> st(v.begin(), v.end());
    v.clear();
    for (auto it = st.begin(); it != st.end(); ++it)
      v.push_back(*it);
    
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i+1; j < v.size(); ++j) {
        for (int k = j+1; k < v.size(); ++k) {
          for (int l = k+1; l < v.size(); ++l) {
            if (v[i] + v[j] + v[k] + v[l] == t) {
              std::vector<int> rr;
              rr.push_back(v[i]);
              rr.push_back(v[j]);
              rr.push_back(v[k]);
              rr.push_back(v[l]);
              r.push_back(rr);
            }
          }
        }
      }
    }
    return r;
  }
};


int main() {
  // std::vector<int> v = {1, 0, -1, 0, -2, 2};
  // int t = 0;
  std::vector<int> v = {-3, -2, -1, 0, 0, 1, 2, 3};
  int t = 0;
  
  Solution s;
  auto r = s.fourSum(v, t);
  for (const auto& rr : r) {
    for (int rrr : rr) {
      printf("%2d ", rrr);
    }
    printf("\n");
  }
  return 0;
}
