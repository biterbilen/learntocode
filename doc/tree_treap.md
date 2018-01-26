<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Abstract](#abstract)
- [Data Structure Treap](#data-structure-treap)
- [Algorithm Split](#algorithm-split)
- [Algorithm Insert](#algorithm-insert)
- [Algorithm Merge](#algorithm-merge)
- [Algorithm Erase](#algorithm-erase)
- [Implementation](#implementation)

<!-- markdown-toc end -->

-------------------------------------------------------------------------------

# Abstract

treap에 대해 정리한다.  skewed binary search tree의 경우 검색 효율이
좋지 않다.  balanced binary search tree는 검색 효율이 좋다. AVL tree,
red-black tree는 balanced tree이긴 하지만 구현이 복잡하자.  treap은
binary search tree의 특성과 heap의 특성을 가지고 있어 balanced binary
search tree이다.  그리고 구현이 간단하여 프로그래밍 문제 해결에
사용하면 좋다.

# Data Structure Treap

treap은 binary search tree의 특성과 heap의 특성을 가지고 있다. treap의
임의의 노드가 가지고 있는 값은 그 노드의 왼쪽 자식 노드들이 가지고
있는 값보다 크고 그 노드의 오른쪽 자식 노드들이 가지고 있는 값보다
작다. 이것은 binary search tree의 특성에 해당된다. treap의 임의의
노드는 우선순위를 가지고 있는 있는데 항상 부모 노드 보다는 우선순위가
낮고 자식 노드 보다는 우선순위가 높다.

# Algorithm Split



# Algorithm Insert

# Algorithm Merge

# Algorithm Erase

# Implementation 

[c++11](/fundamentals/tree/treap/a.cpp)
