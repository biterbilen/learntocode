/* Copyright (C) 2018 by iamslash */

#include <cstdio>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
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
  Solution s;
  // TreeNode* p = new TreeNode(2,
  //                           new TreeNode(1),
  //                           new TreeNode(3));
  // TreeNode* p = new TreeNode(5,
  //                           new TreeNode(1),
  //                            new TreeNode(4,
  //                                         new TreeNode(3),
  //                                         new TreeNode(6)));
  TreeNode* p = new TreeNode(1,
                             new TreeNode(1),
                             NULL);
  printf("%s\n", s.isValidBST(p) ? "true" : "false");
  return 0;
}
