/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/790/

#include <cstdio>

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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode*r) {
    val = x;
    left = l;
    right = r;
  }
};


// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1

class Solution {
 public:
  int _kth(TreeNode* node, int k) {

  }
  int kthSmallest(TreeNode* root, int k) {
    
  }
};

int main() {
  TreeNode* root = new TreeNode(3,
                                new TreeNode(1, NULL,
                                             new TreeNode(2)),
                                new TreeNode(4));
  int k = 1;
  
  Solution s;
  printf("%d\n", s.kthSmallest(root, k));
  return 0;
}
