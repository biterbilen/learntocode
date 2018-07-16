/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/804/

#include <cstdio>
#include <vector>

// [4, 5, 6, 7, 0, 1, 2] [4, 5, 6, 7, 0, 1, 2]
//
class Solution {
 public:
  int search(std::vector<int>& v, int t) {
    int rr = -1;
    std::vector<int> vv = v;
    vv.insert(vv.end(), v.begin(), v.end());
    int k = 0;

    // get k index to find a least number
    for (int i = 0; i < v.size(); ++i, ++k) {
      if (i > 0 && v[i-1] > v[i])
        break;      
    }

    // binary search
    int l = k, m, r = k + v.size() - 1;
    // printf("%d %d %d\n", l, m, r);
    // l
    //   m
    //     r
    // 1 2 3
    while (l <= r) {
      m = (l + r) / 2;
      if (vv[m] == t) {
        rr = m % v.size();
        break;
      } else if (t < vv[m]) {
        r = m-1;
      } else {
        l = m+1;
      }
    }
    
    return rr;
  }
};

int main() {
  // std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};
  // int t = 0;
  std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};
  int t = 3;  
  Solution s;
  printf("%d\n", s.search(v, t));  
  return 0;
}
