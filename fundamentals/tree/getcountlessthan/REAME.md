# Problem

숫자들의 배열이 주어졌다. 특정 숫자 `X`보다 작은 숫자들이 몇개 인지 구해
보자. 이때 배열이 한개 주어지면 특정 숫자는 여러번 주어진다.

# Idea

[treap](tree_treap.md)을 이용하여 해결해보자.
[treap](tree_treap.md)은 랜덤한 우선순위를 이용하여 가능한 BST의
균형을 유지하기 때문에 검색시간을 `O(lgN)`으로 수행할 수 있다. treap의
Node는 `size`를 가지고 있다. `set_left`, `set_right`할때 마다
`size`를 갱신하자.

재귀적으로 해결하기 위해 다음과 같이 부분문제 `count_less_than`을 정의한다.

```
int count_less_than(Node* root, int X)
root   : 서브트리의 루트노드
X      : 비교 대상의 숫자
return : X보다 작은 key를 갖는 노드들의 개수
```

다음과 같이 여러 가지 경우를 고려하여 재귀적으로 해결하자.

* `root`가 `NULL`이면 0을 리턴한다.
* `X` 가 `root->key` 보다 작거나 같으면 대상이 되는 노드들은 `root` 의
  왼쪽 자식들중에 존재한다. 계속 해서 왼쪽 자식을 탐색하자.
* `X` 가 `root->key` 보다 크면 대상이 되는 노드들은 `root` 의 왼쪽
  자식들 전부와 오른쪽 자식들 중 일부에 존재한다. 계속 해서 오른쪽
  자식을 탐색하자. 이때 왼쪽 자식들 개수와 `root` 자신의 개수 하나 그리고
  오른쪽 자식들을 탐색한 결과를 모두 더해서 리턴한다.
  
```
       10
      /  \
     7   15
    / \
   5   9 
  / \ 
 1   6 
  
count_less_than(#10, 15) : 6
_count_less_than(#15, 15) : 0
__count_less_than(NULL, 15) : 0
```

# Implementation

[c++11](a.cpp)

# Time Complexity

`O(lgN)`

# Space Complexity

```
O(N)   : Treap
O(lgN) : call stack
```

