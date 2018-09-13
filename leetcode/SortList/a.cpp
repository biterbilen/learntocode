/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/117/linked-list/840

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  ListNode* merge(ListNode* l, ListNode* r) {
    // base condition
    if (l == NULL)
      return r;
    if (r == NULL)
      return l;

    // recursion
    if (l->val < r->val) {
      l->next = merge(l->next, r);
      return l;
    } else {
      r->next = merge(l, r->next);
      return r;
    }
  } 
  ListNode* sortList(ListNode* h) {
    // base condition
    if (h == NULL || h->next == NULL)
      return h;
    ListNode* p1 = h;
    ListNode* p2 = h;
    ListNode* pre = h;

    while (p2 != NULL && p2->next != NULL) {
      pre = p1;
      p1 = p1->next;
      p2 = p2->next->next;
    }
    pre->next = NULL;

    // recursion
    ListNode* l = sortList(h);
    ListNode* r = sortList(p1);
    
    return merge(l, r);
  }
};

int main() {
  ListNode* p = new ListNode(4,
                             new ListNode(2,
                                          new ListNode(1,
                                                       new ListNode(3))));
  Solution s;
  ListNode* r = s.sortList(p);

  while (r) {
    printf("%d ", r->val);
    r = r->next;
  }
  printf("\n");
  return 0;
}
