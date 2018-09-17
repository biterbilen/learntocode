/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

#include <cstdio>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  std::vector<TreeNode*> m_r;
  std::vector<TreeNode*> generateTrees(int n) {
    return m_r;
  }
};

void printt(TreeNode* t) {
  if (t) {
    printf("%d ", t->val);
    printt(t->left);
    printt(t->right);
  } else {
    printf("null ");
  }
}

int main() {
  int n = 3;
  
  Solution s;
  auto r = s.generateTrees(n);
  for (TreeNode* t : r) {
    printt(t);
    printf("\n");
  }
  
  return 0;
}
