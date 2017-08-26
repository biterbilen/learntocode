# Abstract

- 양방향 리스트에 대해 적는다.

# Implementation

- 양방향 리스트에서 원소를 삭제하고 복구하는 방법을 구현해 본다.

```cpp
struct ListNode {
  int element;
  ListNode *prev, *next;
};

void delete_node(ListNode* node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

void recover_node(ListNode* node) {
  node->prev->next = node;
  node->next->prev = node;
}
```