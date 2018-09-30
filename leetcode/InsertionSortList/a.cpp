// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <limits>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

//   h
//   5 6 1 3
// p
//   b
//     q
//       r
class Solution {
 public:
  ListNode* insertionSortList(ListNode* h) {
    if (h == NULL || h->next == NULL)
      return h;
    ListNode v(std::numeric_limits<int>::min());
    v.next = h;

    ListNode* p = &v, *b = h, *q = h->next, *r = q->next;
    while (q) {
      r = q->next;
      for (p = &v; p->next != q; p = p->next) {
        // swap
        if (p->next->val > q->val) {
          b->next = r;
          
        }
      }
      b = b->next;
      q = r;
    }
    return h;
  }
};

int main() {
  return 0;
}


