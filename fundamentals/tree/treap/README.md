<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Abstract](#abstract)
- [Data Structure Treap](#data-structure-treap)
- [Algorithm Search](#algorithm-search)
    - [Idea](#idea)
    - [Time Complexity](#time-complexity)
- [Algorithm Split](#algorithm-split)
    - [Idea](#idea-1)
    - [Time Complexity](#time-complexity-1)
- [Algorithm Insert](#algorithm-insert)
    - [Idea](#idea-2)
    - [Time Complexity](#time-complexity-2)
- [Algorithm Merge](#algorithm-merge)
    - [Idea](#idea-3)
    - [Time Complexity](#time-complexity-3)
- [Algorithm Erase](#algorithm-erase)
    - [Idea](#idea-4)
    - [Time Complexity](#time-complexity-4)
- [Implementation](#implementation)
- [References](#references)

<!-- markdown-toc end -->

-------------------------------------------------------------------------------

# Abstract

treap에 대해 정리한다.  bst중 skewed binary search tree의 경우 검색
효율이 좋지 않다. 검색 효율을 좋게하기 위해 bst를 balanced binary
search tree로 변환 해야 한다. AVL tree, red-black tree는 balanced
tree이긴 하지만 구현이 복잡하다.  treap은 binary search tree의 특성과
heap의 특성을 가지고 있어 가능한 균형을 유지한다. 그리고 구현이
간단하여 프로그래밍 문제 해결에 사용하면 좋다.

# Data Structure Treap

treap은 binary search tree의 특성과 heap의 특성을 가지고 있다. treap의
임의의 노드가 가지고 있는 key는 그 노드의 왼쪽 자식 노드들이 가지고
있는 key보다 크고 그 노드의 오른쪽 자식 노드들이 가지고 있는 key보다
작다. 이것은 binary search tree의 특성에 해당된다. treap의 임의의
노드는 우선순위를 가지고 있는데 항상 부모 노드 보다는 우선순위가 낮고
자식 노드 보다는 우선순위가 높다. 우선순위는 노드가 새로 만들어질 때
랜덤하게 부여된다. 랜덤하게 부여된 우선순위가 bst의 balance를
유지하도록 도와준다.

treap의 임의의 노드는 priority, key를 갖는다.

# Algorithm Search

## Idea

binary search tree의 검색과 같다. 특정 key가 검색될때까지 재귀적으로
탐색한다.

## Time Complexity

`O(lgN)`

# Algorithm Split

## Idea

트리를 특정 key을 기준으로 쪼갠다. 첫번째 서브 트리는 key보다 작은
값을 갖는 노드들의 모임이다.  두번째 서브 트리는 key보다 큰 값을 갖는
노드들의 모임이다. 재귀적으로 해결하기 위해 다음과 같이 부분 문제를
정의한다.

```
<Node*, Node*> Split(Node* root, int key)
root   : 쪼개는 대상에 해당하는 서브트리의 루트노드
key    : 쪼개는 기준에 해당하는 key
return : key보다 작은 값들을 갖는 노드들, key보다 큰 값들을 갖는 노드들
```

다음과 같이 여러가지 경우를 고려해서 재귀적으로 해결한다.

* `root`가 `NULL`이면 `NULL,NULL`을 리턴한다.
* `root->key`가 `key`보다 작으면 `Split(root->right, key)` 결과를
  `first,second`라고 하자. `root->right`을 `first`로 설정하고 `root,second`를 리턴한다.
* `root->key`가 `key`보다 크면 `Split(root->left, key)` 결과를
  `first,second`라고 하자. `root->left`을 `second`로 설정하고 `first, root`를 리턴한다.

* 다음은 여러가지 상황의 Split 예제들이다. 원숫자는 노드를 표현하고
  부분문제에서 `_`는 call stack의 깊이를 의미한다. 그리고 부분문제와
  함께 등장하는 콜론 이후는 해당 부분문제의 리턴값을 의미한다.

```
key: 5

  ②  =>    ②
  
Split(②, 5) : ②, NULL
_Split(NULL, 5) : NULL, NULL
```

```
key: 1

  ②  =>    ②
  
Split(②, 1) : NULL, ②
_Split(NULL, 1) : NULL, NULL
```

```
key: 5

  ②        ②
 / \  =>   / 
①  ⑦     ①  ⑦

Split(②, 5) : ②, ⑦
_Split(⑦, 5) : NULL, ⑦
__Split(NULL, 5) : NULL, NULL
```

```
key: 10

  ②       ②
 / \  =>  / \
①  ⑦    ①  ⑦

Split(②, 10) : ②, NULL
_Split(⑦, 10) : ⑦, NULL 
__Split(NULL, 10) : NULL, NULL
```

Split은 Insert에서 이용한다.

## Time Complexity

`O(lgN)`

# Algorithm Insert

## Idea

재귀적으로 해결하기 위해 다음과 같이 부분 문제를 정의한다.

```
Node* Insert(Node* root, Node* node)
root   : 삽입의 대상에 해당되는 서브트리의 루트 노드
node   : 삽입할 노드
return : 노드가 삽입된 서브트리의 루트노드
```

다음과 같은 경우를 고려해서 재귀적으로 해결한다.

* root가 NULL이면 node를 리턴한다.
* root의 priority가 node의 priority보다 낮으면 root를 포함한
  서브트리를 node의 key를 기준으로 둘로 쪼깬 서브트리들을
  node의 자식들로 설정한다.
* root의 priority가 node의 priority보다 크고 node의 key가 root의
  key보다 작으면 root의 왼쪽 자식을 root로 하여 node를 삽입한다.
* root의 priority가 node의 priority보다 크고 node의 key가 root의
  key보다 크면 root의 오른쪽 자식을 root로 하여 node를 삽입한다.

* 다음은 여러가지 상황의 Insert 예제들이다. 원숫자는 노드와 key를
  표현하고 부분문제에서 `_`는 call stack의 깊이를 의미한다. 그리고
  부분문제와 함께 등장하는 콜론 이후는 해당 부분문제의 리턴값을
  의미한다.

```
node: ③
prioirty: ③ < ②

  ②  =>    ②
             \
              ③
Insert(②, ③) : ②
_Insert(NULL, ③) : ③
```

```
node: ③
prioirty: ③ > ②

  ②  =>    ③
           /
          ②
Insert(②, ③) : ③
_Split(②, 3) : ②, NULL
```

## Time Complexity

`O(lgN)`

# Algorithm Merge

## Idea

두개의 서브트리를 합친다. 재귀 적으로 해결하기 위해 다음과 같이 부분
문제를 정의한다.

```
Node* Merge(Node* a, Node* b)
a     : 왼쪽 서브트리의 루트이다.
b     : 오른쪽 서브트리의 루트이다.
return: 합쳐진 서브트리의 루트이다.
```

Erase에서 사용된다. 특정 서브트리의 루트를 지우면 남게되는 두개의
서브트리가 각각 a, b이다. a를 루트로 하는 서브트리의 모든 key는 b를
루트로 하는 서브트리의 모든 key보다 작다. 우선순위를 비교하여
우선순위가 더 높은 노드를 새로운 루트로 설정한다.

* 다음은 여러가지 상황의 Merge 예제들이다. 원숫자는 노드와 key를
  표현하고 부분문제에서 `_`는 call stack의 깊이를 의미한다. 그리고
  부분문제와 함께 등장하는 콜론 이후는 해당 부분문제의 리턴값을
  의미한다.

```
a: ②
a: ③
prioirty: ③ < ②

  ② ③ =>    ②
               \
                ③
Merge(②, ③) : ②
_Merge(NULL, ③) : ③
```

## Time Complexity

`O(lgN)`

# Algorithm Erase

## Idea

특정 key를 갖는 노드를 지운다. 재귀 적으로 해결하기 위해 다음과 같이 부분
문제를 정의한다.

```
Node* Erase(Node* root, key)
root  : 서브트리의 루트
key   : 삭제할노드의 key
return: 삭제된 서브트리의 새로운 루트
```

루트의 key가 인자의 key와 같을때까지 탐색한다. 만약 같다면 루트를 제거하고
남게되는 두개의 서브트리를 앞서 언급한 Merge를 이용하여 합친다. 그리고 새로운
루트를 리턴한다.

## Time Complexity

`O(lgN)`

# Implementation 

[c++11](/fundamentals/tree/treap/a.cpp)

# References

* [Treap Lecture](https://courses.cs.washington.edu/courses/cse326/00wi/handouts/lecture19/sld017.htm)
