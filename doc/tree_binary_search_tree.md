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

특정 키값을 삽입해 보자. 그 키값이 삽입할 적당한 위치까지 재귀적으로
탐색하여 삽입한다.

## Time Complexity

`O(lgN)`

# Algorithm Delete

## Idea

다음과 같은 경우를 고려하여 재귀적으로 노드를 삭제하자.

* 삭제 하려는 노드가 leaf node인 경우 그냥 지우자.
* 삭제 하려는 노드가 하나의 자식을 갖는 경우 일단 지우고 자식 노드를 삭제한 노드 위치로 재배치 한다.
* 삭제 하려는 노드가 두개의 자식을 갖는 경우 일단 지우고 오른쪽 자식들중 가장 작은 노드를 삭제한 노드 위치로 재배치 한다.

## Time Complexity

`O(lgN)`

# Implementation

[c++11](/fundamentals/tree/binarysearchtree/a.cpp)

