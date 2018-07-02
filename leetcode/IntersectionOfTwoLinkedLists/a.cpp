// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/785/

#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    return NULL;
  }
};

void dump(ListNode* p) {
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  ListNode* x = new ListNode(0);
  x->next = new ListNode(1);
  ListNode* y = new ListNode(2);
  y->next = new ListNode(3);
  ListNode* z = new ListNode(4);
  z->next = new ListNode(5);
  x->next->next = z;
  y->next->next = z;

  Solution s;
  // dump(s.getIntersectionNode(x, y));
  dump(z);
  return 0;
}
