// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <queue>
#include <vector>



class Solution {
 private:
 public:
  int solve(int N, int B, const std::vector<int>& a) {
    std::vector<int> clinic(a.size(), 1);
    std::vector<int> load(a.size());  // m_load[i] = population / clinic
    for (int i = 0; i < a.size(); ++i) {
      load[i] = a[i] / clinic[i];
    }
    std::priority_queue<int, std::vector<int>, decltype(mycomp)> pq()
    for (int i = 0; i < B - N; ++i) {
      
    }
    return r;
  }
};

int main() {
  Solution s;
  std::vector<int> v = {200000, 500000};
  printf("%d\n", s.solve(2, 7, v));
  return 0;
}
