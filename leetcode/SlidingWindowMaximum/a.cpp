/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/837/

#include <cstdio>
#include <vector>
#include <limits>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& V, int k) {
    std::vector<int> rs;
    int l = 0;
    int r = 0;
    int m = std::numeric_limits<int>::min(); // left index, right index, max value
    // check first slide
    while (r < k) {
      m = std::max(m, V[r++]);
    }
    rs.push_back(m);
    // check others
    while (r < V.size()) {
      
    }
    return rs;
  }
};

int main() {
  std::vector<int> V = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  
  Solution sln;
  auto r = sln.maxSlidingWindow(V, k);
  for (int rr : r) {
    printf("%d ", rr);
  }
  printf("\n");
  
  return 0;
}
