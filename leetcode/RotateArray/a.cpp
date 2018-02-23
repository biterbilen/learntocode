/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// 1,2,3,4,5,6,7

class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
      return;
    for (int j = 0; j < k; ++j) {
      int t = nums[0];
      nums[0] = nums.back();
      for (int i = 1; i < nums.size(); ++i) {
        int o = nums[i];
        nums[i] = t;
        t = o;
      }      
    }
  }
};

int N, K;

int main() {
  
  Solution s;
  scanf("%d %d", &N, &K);
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &v[i]);
  
  s.rotate(v, K);
  for (int e : v) {
    printf("%d ", e);
  }
  printf("\n");
  return 0;
}
