// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/word-search/description/

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent
// cell, where "adjacent" cells are those horizontally or vertically
// neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void print_v_bool(vector<vector<bool>> v) {

}

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 1};
    bool _exist(vector<vector<char>>& board, vector<vector<bool>>& visited, 
                int i, int j, string word) {
        printf("[%d][%d]\n", i, j);      
        // base condition
        if (i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size())
          return false;
        if (visited[i][j] == true)
          return false;
        visited[i][j] = true;
        if (word.size() == 0)
          return true;
        if (board[i][j] != word[0])
          return false;

        // recursion
        printf("[%d][%d] %c\n", i, j, word[0]);
        for (int k = 0; k < 4; ++k) {
          if (_exist(board, visited,
                     i+dx[k], i+dy[k], word.substr(1)))
            return true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited =
            vector<vector<bool>>(board.size(),
                                 vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
              if ((visited[i][j] == false) &&
                  (word.size() > 0) &&
                  (board[i][j] == word[0]) &&
                  _exist(board, visited, i, j, word.substr(1)))
                    return true;
            }
        }
        return false;
    }
};

int main() {
  vector<vector<char>> b = {{'A', 'B', 'C', 'E'},
                            {'S', 'F', 'C', 's'},
                            {'A', 'D', 'E', 'E'}};
  Solution s;
  printf("%s", s.exist(b, "ABCCED") ? "true" : "false");
}
