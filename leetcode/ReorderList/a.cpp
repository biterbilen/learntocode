// Copyright (C) 2018 by iamslash
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

//   h
// a 1 2 4 3
//   b
//     p
//       q
class Solution {
 public:
  void reorderList(ListNode* h) {
    if (!h || !h->next)
      return;

    ListNode* p = h, *q = h->next, *r = h;
    // separate 2 lists
    while (q && q->next) {
      p = p->next;
      q = q->next->next;
    }
    ListNode* h2 = p->next;
    q = p->next;
    p->next = NULL;
    // reverse 2nd list
    while (q) {
      r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    // merge 2 lists
    p = h;
    q = h2;
    while (p) {
      r = p->next;
      p = p->next = q;
      q = r;
    }
  }
};

int main() {
  return 0;
}
