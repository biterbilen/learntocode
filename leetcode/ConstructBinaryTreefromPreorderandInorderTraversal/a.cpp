// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/788/

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
  explicit TreeNode(int v) : val(v), left(NULL), right(NULL) {}
  explicit TreeNode(int v, TreeNode* l, TreeNode* r) :
      val(v), left(l), right(r) {}
};

class Solution {
 public:
  TreeNode* root = NULL;
  TreeNode* _solve(TreeNode* parent, std::vector<int>& pre, std::vector<int>& ino) {
    // base condition
    if (pre.size() == 0)
      return;

    // job
    int v = *pre.erase(pre.begin());
    std::vector<int> pre_l;
    std::vector<int> pre_r;
    std::vector<int> ino_l;
    std::vector<int> ino_r;
    
    // recursion
    parent->left = 
  }
  TreeNode* buildTree(std::vector<int>& pre, std::vector<int>& ino) {
    return _solve(root, pre, ino);
  }
};

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

  //   3
  //  / \
  // 9  20
  //   /  \
  //  15   7

// print preorder traversal
void dump(TreeNode* r) {
  // base condition
  if (r == NULL)
    return;

  // task
  printf("%d ", r->val);

  // recursion
  if (r->left) dump(r->left);
  if (r->right) dump(r->right);
}

int main() {
  std::vector<int> a = {3, 9, 20, 15, 7};
  std::vector<int> b = {9, 3, 15, 20, 7};

  Solution s;
  TreeNode* r = s.buildTree(a, b);

  dump(r);
  return 0;
}
