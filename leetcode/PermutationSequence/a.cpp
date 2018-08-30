/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/permutation-sequence/description/

#include <cstdio>
#include <string>
#include <vector>

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
//
// 3

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    std::string nums = "123456789";
    std::vector<int> fcts(9, 1);
    std::string r;
    for (int i = 1; i < 10; ++i) {      
      fcts[i] = fcts[i-1] * (i+1);
    }
    //
    fcts[n-1] / n

    return r;
  }
};


int main() {
  Solution s;
  printf("%s\n", s.getPermutation(3, 3).c_str());
  return 0;
}
