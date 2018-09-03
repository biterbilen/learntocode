/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/837/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& V, int k) {
    std::vector<int> r;

    return r;
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
