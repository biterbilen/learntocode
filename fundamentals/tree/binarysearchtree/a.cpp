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
  explicit Node(int _val) {
    val = _val;
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
  // base condition
  if (root == NULL || root->val == val)
    return root;
  // recursion
  if (root->val < val)
    return Search(root->right, val);
  return Search(root->left, val);
}

Node* Insert(Node* root, int val) {
  // base condition
  if (root == NULL)
    return new Node(val);
  // recursion
  if (val < root->val)
    root->left = Insert(root->left, val);
  else
    root->right = Insert(root->right, val);
  return root;
}



int main() {
  Node* root = new Node();

  root = Insert(root, 50);
  root = Insert(root, 30);
  root = Insert(root, 20);
  root = Insert(root, 40);
  root = Insert(root, 70);
  root = Insert(root, 60);
  root = Insert(root, 80);

  return 0;
}
