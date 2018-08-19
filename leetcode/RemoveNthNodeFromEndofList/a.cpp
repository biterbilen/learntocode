// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* pnext) : val(x), next(pnext) {}
};


// b      
// r        
//   h
// 1 2 3 4 5
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* ph, int n) {
    if (n <= 0)
      return ph;
    ListNode* pb = ph;
    ListNode* pr = ph;

    while (ph) {
      if (n == 0) {
        pb = pb->next;
        pr = pb->next;
        ph = ph->next;
      } else if (n == 1) {
        
        --n;
      } else {
        ph = ph->next;
        --n;
      }
    }

    pb->next = pr->next;
    return ph;
  }
};

int main() {
  Solution s;
  ListNode* p = new ListNode(1,
                  new ListNode(2,
                    new ListNode(3,
                      new ListNode(4,
                        new ListNode(5)))));
  ListNode* pp = s.removeNthFromEnd(p, 2);
  ListNode* phead = pp;
  while (phead) {
    printf("%d ", phead->val);
    phead = phead->next;
  }
  return 0;
}
