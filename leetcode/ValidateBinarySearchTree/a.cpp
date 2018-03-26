/* Copyright (C) 2018 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    // base condition
    if (root == NULL)
      return true;
    TreeNode* cl = root->left;
    TreeNode* cr = root->right;
    if (cl != NULL && cr == NULL && root->val <= cl->val)
      return false;
    else if (cl == NULL && cr != NULL && root->val >= cr->val)
      return false;
    else if (cl != NULL && cr != NULL &&
             (root->val <= cl->val || root->val >= cr->val))
      return false;
    // recursion
    return isValidBST(root->left) && isValidBST(root->right);
  }
};

int main() {
  return 0;
}
