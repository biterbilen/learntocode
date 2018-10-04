/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <cstdio>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class BSTIterator {
 public:
  TreeNode* m_next;
  BSTIterator(TreeNode *t) {
    m_next = t;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return m_next ? true : false;
  }

  /** @return the next smallest number */
  int _next(TreeNode* t) {

  }
  int next() {
    int rslt = m_next->val;
    if (m_next->left)
      m_next = m_next->left;
    else if (m_next->right)
      m_next = m_next->right;
    else
      m_next = NULL;
    return rslt;
  }
};

int main() {

  TreeNode* root = new TreeNode(1,
                                NULL,
                                new TreeNode(2));
  
  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) {
    // std::cout << i.next();
    printf("%d\n", i.next());
  }
  
  return 0;
}
