/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/

#include <cstdio>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    if (isBadVersion(1))
      return 1;

    // binary search
    int l = 1;
    int r = n;
    int m = (l+r)/2;

    //   l r 
    // 1 2 3 4
    //     b
    // l   m   r
    // 1 2 3 4 5
    //       b
    while (l != (m-1) || (m+1) != r) {
      printf("%d %d %d\n", l, m, r);
      if (isBadVersion(m) && isBadVersion(r)) {
        r = m;
      } else {
        l = m;
      }
      m = (l + r) / 2;
    }
        
    return ;
  }
};

bool isBadVersion(int version) {
  return version >= 3;
}

int main() {
  int N = 4;
  Solution s;
  printf("%d\n", s.firstBadVersion(N));
  return 0;
}
