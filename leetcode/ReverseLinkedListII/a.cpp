// Copyright (C) 2018 by iamslash

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* h, int m, int n) {
    //   f
    // l
    //         r
    //   b
    //     p
    // 1 2 3 4 5
    ListNode* b = h;
    ListNode* p = h;  // iterator pointer
    ListNode* l = NULL;  // left block pointer 
    ListNode* r = NULL;  // right block pointer
    ListNode* f = NULL;  // mid block point of first one

    while (n > 0) {
      --m; --n; 
      if (m == 1) {
        l = p;
        f = l->next;
      }
      if (n == 0) {
        r = p->next;
      }
      if (m <= 0) {
        ListNode* t = p->next;
        p->next = b;
        p = t;
      } else {
        p = p->next;
      }
      if (p != h)
        b = b->next;
    }

    l->next = p;
    f->next = r;
    return h;
  }
};

int main() {

  ListNode* h = new ListNode(1,
                             new ListNode(2,
                                          new ListNode(3,
                                                       new ListNode(4,
                                                                    new ListNode(5)))));
  int m = 2, n = 4;
  
  Solution s;
  ListNode* p = s.reverseBetween(h, m, n);

  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  return 0;
}
