// Copyright (C) 2018 by iamslash

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

#include <cstdio>

class Node {
 public:  
  int val;
  Node* left;
  Node* right;
  Node(int _val, Node* _left, Node* _right) :
      val(_val), left(_left), right(_right) {}
};

Node * LCA(Node* root, int n1, int n2) {
  return NULL;
}

int main() {
  Node * root = new Node( 1, new Node(2,
                                      new Node(4, NULL, NULL),
                                      new Node(5, NULL, NULL)),
                             new Node(3,
                                      new Node(6, NULL, NULL),
                                      new Node(7, NULL, NULL)));
  // Node* root = new Node (1, NULL, NULL);
  return 0;
}
