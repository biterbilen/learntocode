// Copyright (C) 2017 by iamslash
#include <string>
#include <vector>
#include <algorithm>

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

std::vector<int> 

std::vector<int> kmp_search(const std::string& h, const std::string& n) {

}

int main() {
  std::string h = "hellomynameisslashmynameisnotfoo";
  std::string n = "myname";
  std::vector<int> r = kmp_search("hellomynameisslashmynameisnotfoo", "myname");
  // std::vector<int> r = GetPartialMatch("aabaabac");
  print_v_int(r);
  
  return 0;
}
