// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>

// 5 2 6 1
// 
class Solution {
 public:
  std::vector<int> countSmaller(std::vector<int>& V) {
    return V;
  }
};


int main() {
  std::vector<int> V = {5, 2, 6, 1};
  
  Solution sln;
  auto rslt = sln.countSmaller(V);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
