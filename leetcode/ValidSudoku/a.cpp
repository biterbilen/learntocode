/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/valid-sudoku/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& B) {
    std::vector<int> S(9, 0);
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[0].size(); ++j) {
        if (B[i][j] == '.')
          continue;
        int n = B[i][j] - '0';
        // check hor bitmask
        if (bm && (0x01 << a))
          return false;
        bm =
      }
    }
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] != S[0])
        return false;
    }
    return true;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  // std::vector<std::vector<char>> B = {
  //   {'8','3','.','.','7','.','.','.','.'},
  //   {'6','.','.','1','9','5','.','.','.'},
  //   {'.','9','8','.','.','.','.','6','.'},
  //   {'8','.','.','.','6','.','.','.','3'},
  //   {'4','.','.','8','.','3','.','.','1'},
  //   {'7','.','.','.','2','.','.','.','6'},
  //   {'.','6','.','.','.','.','2','8','.'},
  //   {'.','.','.','4','1','9','.','.','5'},
  //   {'.','.','.','.','8','.','.','7','9'}
  // };
  
  Solution s;
  printf("%s\n", s.isValidSudoku(B) ? "true" : "false");
  return 0;
}
