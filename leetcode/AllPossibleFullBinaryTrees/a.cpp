// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/all-possible-full-binary-trees/description/

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

//       0
//      / \
//     0   0
//    / \
//   0   0
//
//       0
//      / \
//     0   0
//        / \
//       0   0
class Solution {
 public:
  std::vector<TreeNode*> allPossibleFBT(int N) {
    std::vector<TreeNode*> r;

    // base condition
    if (N == 1) {
      r.push_back(new TreeNode(0));
      return r;
    }
    if (N < 1 || N % 2 == 0) {
      return r;
    }

    // recursion
    for (int i = 1; i < N; i += 2) {
      std::vector<TreeNode*> l = allPossibleFBT(i);
      std::vector<TreeNode*> r = allPossibleFBT(N-1-i);
      printf("%d %lu %lu\n", N, l.size(), r.size());

      for (int j = 0; j < l.size(); ++j) {
        for (int k = 0; k < r.size(); ++k) {
          printf("%d %d\n", j, k);
          r.push_back(new TreeNode(0));
          r.back()->left = l[j];
          r.back()->right = r[k];
        }
      }
    }
    return r;
  }
};

int main() {
  Solution s;
  auto r = s.allPossibleFBT(3);
  return 0;
}
