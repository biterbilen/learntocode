// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* y) : val(x), next(y) {}
};

//         t
//   b
//     h
// 1 2 3 4
class Solution {
 public:
  ListNode* swapPairs(ListNode* h) {
    ListNode* r = h;
    ListNode* b = h;
    ListNode* t = NULL;
    
    while (h && h->next) {
      // swap
      if (b == h) {
        t = h->next->next;
        r = h->next;
        r->next = h;
        h->next = t;
      } else {
        t = h->next->next;
        b->next = h->next;
        h->next = h->next->next;
        b->next->next = 
      }
      b = h;
      h = h->next;
    }

    return r;
  }
};

int main() {
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3,
    new ListNode(4))));

  Solution s;
  ListNode* p = s.swapPairs(h);
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  return 0;
}
