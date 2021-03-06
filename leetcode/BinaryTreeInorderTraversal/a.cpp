/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/786/

#include <cstdio>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};


class Solution {
public:
  std::vector<int> r;
  void _traverse(TreeNode* node) {
    // base condition
    if (node == NULL)
      return;
    
    // recursion
    if (node->left)
      _traverse(node->left);
    r.push_back(node->val);
    if (node->right)
      _traverse(node->right);
  }
  std::vector<int> inorderTraversal(TreeNode* root) {
    _traverse(root);
    return r;
  }
};


// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
int main() {
  TreeNode* p = new TreeNode(1,
                             NULL,
                             new TreeNode(2,
                                          new TreeNode(3, NULL, NULL),
                                          NULL));
  Solution s;
  std::vector<int> r = s.inorderTraversal(p);
  for (int n : r)
    printf("%d ", n);
  printf("\n");
  return 0;
}
