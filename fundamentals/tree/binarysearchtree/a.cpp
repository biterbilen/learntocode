// Copyright (C) 2018 by iamslash

#include <cstdio>

struct Node {
  int val;
  Node* left;
  Node* right;
  Node() {
    val = -1;
    left = NULL;
    right = NULL;
  }

  explicit Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

Node* Search(Node* root, int val) {
  if (root == NULL || root->val == val)
    return root;
  if (root->val < val)
    return Search(root->right, val);
  return Search(root->left, val);
}

int main() {
  return 0;
}
