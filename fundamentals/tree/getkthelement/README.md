# Problem

[k-th smallest element in BST](https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1)

# Idea

[treap](tree_treap.md)을 이용하여 해결해보자.
[treap](tree_treap.md)은 랜덤한 우선순위를 이용하여 가능한 BST의
균형을 유지하기 때문에 검색시간을 `O(lgN)`으로 수행할 수 있다. treap의
Node는 `size`를 가지고 있다. `set_left`, `set_right`할때 마다
`size`를 갱신하자.

재귀적으로 해결하기 위해 다음과 같이 부분문제 `kth` 를 정의한다.

```
Node* kth(Node* root, int k);
root   : 서브트리의 루트노드
k      : 서수
return : k번째 노드
```

다음과 같은 여러가지 경우를 고려하여 재귀적으로 해결하자.

* `root`의 왼쪽 자식이 존재 한다면 그녀석의 `size`를 얻어
  `left_size`에 저장하자. `size`의 범위는 [1,3] 이다.
* `k` 가 `left_size + 1` 과 같다면 `root`가 바로 그 녀석이다.  다음은
  1번째 작은 녀석을 찾는 예이다.  `#5` 는 `key`가 `5`인 노드를
  표현한 것이다.

```
    1
     \
      5
      
kth(#5, 1) : #1
```

* `k` 가 `left_size` 보다 작거나 같으면 `root` 의 자식들중
  해답이 있다는 얘기이다. 다음은 1번째 작은 녀석을 찾는 예이다.
  
```
    3
   / \
  1   5
      
kth(#3, 1) : #1
_kth(#1, 1) : #1
```

* `k` 가 `left_size + 1` 보다 크면 `root` 의 왼쪽 자식들중에는
  해답이 없다는 얘기이다. 그래서 `root` 의 오른쪽 자식들로 탐색의 방향을
  전환한다. 이때 k는 `root` 의 왼쪽 자식들 수 만큼 감소 되어야 한다.
  다음은 3번째 작은 녀석을 찾는 예이다.
  
  
```
    3
   / \
  1   5
      
kth(#3, 3) : #5
_kth(#5, 1) : #5
``` 

# Implementation

* [c++11](a.cpp)

# Time Complexity

`O(lgN)`

# Space Complexity

```
O(N)   : Treap
O(lgN) : call stack
```
