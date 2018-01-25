<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Abstract](#abstract)
- [Data Structure BST](#data-structure-bst)
- [Algorithm Search](#algorithm-search)
    - [Idea](#idea)
    - [Time Complexity](#time-complexity)
- [Algorithm Insert](#algorithm-insert)
    - [Idea](#idea-1)
    - [Time Complexity](#time-complexity-1)
- [Algorithm Delete](#algorithm-delete)
    - [Idea](#idea-2)
    - [Time Complexity](#time-complexity-2)
- [Implementation](#implementation)

<!-- markdown-toc end -->

******

# Abstract

이진 검색 트리에 대해 정리한다.

# Data Structure BST

다음과 같은 특성을 갖는 트리를 이진검색 트리라고 한다.

중복된 키값을 갖는 노드는 없다.  특정 노드의 왼쪽 자식노드의 키값은
부모 노드의 키값보다 작다.  특정 노드의 오른쪽 자식노드의 키값은 부모
노드의 키값보다 크다.  특정 노드의 왼쪽 자식 노드를 루트로 하는
서브트리와 오른쪽 자식 노드를 루트로 하는 서브트리는
이진검색트리이어야 한다.

# Algorithm Search

## Idea

특정 키값을 검색해 보자. 그 키값이 검색될때까지 루트 노드부터 자식들을
따라 간다.

## Time Complexity

`O(lgN)`

# Algorithm Insert

## Idea

## Time Complexity

`O(lgN)`

# Algorithm Delete

## Idea

## Time Complexity

`O(lgN)`

# Implementation

[c++11](/fundamentals/tree/binarysearchtree/a.cpp)

