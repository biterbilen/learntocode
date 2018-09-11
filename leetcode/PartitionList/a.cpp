/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/partition-list/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* h, int x) {
    return h;
  }
};

int main() {
  ListNode* h = new ListNode(1,
                             new ListNode(4,
                             new ListNode(3,
                             new ListNode(2,
                             new ListNode(5,
                                          new ListNode(2))))));
  int x = 3;
  Solution s;
  ListNode* p = s.partition(h, x);

  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  
  return 0;
}
