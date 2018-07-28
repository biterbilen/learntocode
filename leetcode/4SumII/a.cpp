// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

class Solution {
 public:
  int fourSumCount(std::vector<int>& A, std::vector<int>& B,
                   std::vector<int>& C, std::vector<int>& D) {
    return 0;
  }
};

int main() {
  std::vector<int> a = { 1,  2};
  std::vector<int> b = {-2, -1};
  std::vector<int> c = {-1,  2};
  std::vector<int> d = { 0,  2};
  
  Solution s;
  printf("%d\n", s.fourSumCount(a, b, c, d));
  return 0;
}
