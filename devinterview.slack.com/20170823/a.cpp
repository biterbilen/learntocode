// Copyright (C) 2017 by iamslash

// You get binary tree.
// You should print out all nodes of specified level.
// ex) binary tree is
//             4
//          /    \
//       2         6
//     /  \       /  \
//   1    3   5      7
//  if level is 2, then 2, 6. if level is 3, then 1, 3, 5, 7
// Source : from Amazon

// g++ a.cpp -std=c++11 -o a.exe

// Time Complexity : O(N)
// Space Complexity : O(1)

#include <cstdio>
#include <queue>
#include <cmath>

class Node {
 public:
  int m_n_val;
  Node* m_p_left;
  Node* m_p_right;
  Node(int n_val, Node* p_left, Node* p_right) {
    m_n_val = n_val;
    m_p_left = p_left;
    m_p_right = p_right;
  }
};

void print_node(Node* p_node, int n_lv) {
  if (n_lv - 1 < 0)
    return;
  // BFS
  std::queue<Node*> q;
  q.push(p_node);
  int n_id = 0;
  int n_left = pow(2, n_lv - 1) - 1;
  int n_right = pow(2, n_lv) - 1;
  while (!q.empty() && n_id < n_right) {
    Node* p_cur = q.front(); q.pop();
    if (n_id >= n_left)
      printf("%d ", p_cur->m_n_val);
    n_id++;
    q.push(p_cur->m_p_left);
    q.push(p_cur->m_p_right);
  }
  printf("\n");
}

int main() {
  Node* root = new Node(4,
                        new Node(2,
                                 new Node(1, NULL, NULL), new Node(3, NULL, NULL)),
                        new Node(6,
                                 new Node(5, NULL, NULL), new Node(7, NULL, NULL)));
  print_node(root, 1);
  print_node(root, 2);
  print_node(root, 3);
  return 0;
}
