// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> rslt;
    if (s.size() <= 10)
      return rslt;
    for (int i = 0; i < s.size() - 10; ++i) {
      
    }
      
    return rslt;
  }
};

int main() {
  std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

  Solution sln;
  auto rslt = sln.findRepeatedDnaSequences(s);
  for (const auto& a : rslt) {
    printf("%s\n", a.c_str());
  }
  printf("\n");
  return 0;
}
