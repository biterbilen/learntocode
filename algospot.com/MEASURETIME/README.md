<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Problem](#problem)
- [Strategy Fenwick Tree](#strategy-fenwick-tree)
    - [Idea](#idea)
    - [Implementation](#implementation)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
- [Strategy Segment Tree](#strategy-segment-tree)
    - [Idea](#idea-1)
    - [Implementation](#implementation-1)
    - [Time Complexity](#time-complexity-1)
    - [Space Complexity](#space-complexity-1)
- [Strategy BST](#strategy-bst)
    - [Idea](#idea-2)
    - [Implementation](#implementation-2)
    - [Time Complexity](#time-complexity-2)
    - [Space Complexity](#space-complexity-2)
- [Strategy Merge Sort](#strategy-merge-sort)
    - [Idea](#idea-3)
    - [Implementation](#implementation-3)
    - [Time Complexity](#time-complexity-3)
    - [Space Complexity](#space-complexity-3)

<!-- markdown-toc end -->


-------------------------------------------------------------------------------

# Problem

[삽입 정렬 시간 재기](https://algospot.com/judge/problem/read/MEASURETIME)

# Strategy Fenwick Tree

## Idea

삽입정렬 할 때 `A[i]` 가 왼쪽으로 몇번 움직이는지를 알려면 
`A[0...i-1]` 에 `A[i]` 보다 큰 수가 몇개 있는지를 알아야 한다.

## Implementation

* [c++11](a.cpp)

## Time Complexity

```
O(NlgN)
```

## Space Complexity

```
O(N) : fendwick tree
```

# Strategy Segment Tree

## Idea

## Implementation

## Time Complexity

## Space Complexity

# Strategy BST

## Idea

## Implementation

## Time Complexity

## Space Complexity

# Strategy Merge Sort

## Idea

## Implementation

## Time Complexity

## Space Complexity
