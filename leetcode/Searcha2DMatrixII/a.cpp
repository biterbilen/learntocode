/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/806/

#include <cstdio>
#include <vector>

// 1 4 7
// 2 5 8
// 3 6 9
// 
class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& v, int t) {
    if (v.empty() || v[0].empty())
      return false;
    
    // binary search y
    int l = 0, m, r = v.size()-1;
    while (l <= r) {
      m = (l+r) / 2;
      if (v[m][0] == t) {
        return true;
      } else if (t < v[m][0]) {
        r = m - 1;
      } else {
        r = m + 1;
      }        
    }
    
    // binary search x
    int y = m;
    l = 0, r = v[0].size()-1;
    while (l <= r) {
      m = (l+r)/2;
      if (v[y][m] == t) {
        return true;
      } else if (t < v[y][m]) {
        r = m - 1;
      } else {
        r = m + 1;
      }                          
    }
    
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> m = {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30},
  };
  int t = 5;
  
  Solution s;
  printf("%s\n", s.searchMatrix(m, t) ? "true" : "false");
  
  return 0;
}
