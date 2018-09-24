// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/843/

#include <cstdio>
#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& B) {
    
    return;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
  };
  Solution s;
  s.solve(B);

  for (const auto& b : B) {
    for (char c : b) {
      printf("%c ", c);
    }
    printf("\n");
  }
  return 0;
}
