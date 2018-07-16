/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> C; // cache
  int A; // amount
  int _solve(int amount, int i) {
    // base condition
    if (amount == 0)
      return 1;
    else if (amount < 0)
      return 0;    
    
    // memoization
    // recursion
    return 0;
  }
  int coinChange(std::vector<int>& coins, int amount) {
    C = std::vector<int>(coins.size(), -1);
    A = amount;
    return _solve(amount, 0);
  }
};

int main() {
  std::vector<int> v = {1, 2, 5};
  int a = 11;
  
  Solution s;
  printf("%d\n", s.coinChange(v, a));
  return 0;
}
