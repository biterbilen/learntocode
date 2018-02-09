<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Abstract](#abstract)
- [Data Structure TrieNode](#data-structure-trienode)
- [Algorithm Insert](#algorithm-insert)
    - [Idea](#idea)
    - [Time Complexity](#time-complexity)
- [Algorithm BuildFailLink](#algorithm-buildfaillink)
    - [Idea](#idea-1)
- [Algorithm Search](#algorithm-search)
    - [Idea](#idea-2)
    - [Time Complexity](#time-complexity-1)
- [Implementation](#implementation)
- [References](#references)

<!-- markdown-toc end -->

-------------------------------------------------------------------------------

# Abstract

ahocorasic algorithm에 대해 적는다.

# Data Structure TrieNode

짚더미에서 여러개의 바늘을 찾을 때 유용한 알고리즘이다. 여러가지의
바늘들로 [Trie](/doc/tree_trie.md)를 만들고 검색 도중 실패 하면
처음부터 다시 하지 말고 중간 어딘가에서 부터 다시 한다. 여러개의
바늘들을 동시에 검색하기 때문에 바늘1을 찾다가 실패하면 바늘2를 찾는
식이다. 다음과 같이 TrieNode를 구성한다.

```
class TrieNode {
    TrieNode* children[26];
    int terminal;
    TrieNode* fail;
    vector<int> output;
}
```

`terminal`은 현재 노드에서 끝나는 바늘 문자열의 번호이다.  `fail`은
현재 노드에서 매칭이 실패 했을때 찾아갈 다음 노드이다.  `output`은 이
노드가 방문 되었을 때 등장하는 바늘 문자열들의 번호이다.

# Algorithm Insert

## Idea

다음과 같은 부문 문제를 정의하고 재귀 적으로 삽입한다.

```
void Insert(const char* key, int order)
```

다음과 같이 여러가지 경우를 고려하여 재귀 적으로 삽입한다.

* `order`는 바늘 문자열의 인덱스이다. `*key`가 NULL이면 `order`를
  `terminal`에 저장하자. 
* `*key`가 NULL이 아니면 `Insert(key + 1, order)` 하자.

## Time Complexity

```
O(M)
```

`M`은 바늘 문자열 길이의 합이다.

# Algorithm BuildFailLink

## Idea

노드가 주어 질 때 각 노드에 대한 실패 연결 `fail`과 바늘 문자열 목록
`output`를 BFS를 기반으로 채워나간다.

```
void BuildFailLink(TrieNode* root)
```

BFS queue에 저장된 노드 `u`의 자식들을 탐색 하면서 다음과 같은 반복을
수행한다.  탐색된 자식을 `v`라 하자. `u`가 루트 노드라면 `v->fail`은
`u`이다. `u`가 루트 노드가 아니라면 `u`의 `fail`에 해당하는 노드 `t`
를 찾는다. `t`는 루트 노드도 아니고 `t->children[edge]`는 NULL이어야
한다. `v->fail`에 `t`를 저장한다.

![](/_img/ahocorasick2.png)

예를 들어 노드 4의 경우를 생각해 보자. `u`는 노드 4, `v`는 노드 5,
`edge`는 `e`이다.  이제 `v->fail`을 채워보자. 초기 `t`는 노드 1
이다. `t`가 루트도 아니고 `t->children[edge]`가 NULL인 동안 `t`를
`t->fail`로 갱신한다. 결국 `t`는 노드 2이다.  그러므로 `v->fail`은
노드 2를 저장하자.

# Algorithm Search

## Idea


예를 들어 다음 그림과 같이 바늘들 `he, she, his, hers` 의 Trie를
구성해 보자.

![](/_img/ahocorasick1.png)

그리고 각 노드들에 대해서 다음 단어가 예상 단어가 아니라면 다른 노드를
찾아가는 failure link를 구성해보자.

![](/_img/ahocorasick2.png)

`shis` 가 짚더미중 일부라고 해보자. `sh` 다음에 `e`가 오지 않고 `i`가
왔으므로 failure link에 의해 `4` 노드 대신 `1` 노드로 간다. 이후 `is`가
오기 때문에 `his`를 검색 할 수 있다.

KMP 역시 짚더미에서 바늘을 찾을 때 바늘의 partial match table을 만들어
검색중 실패시 처음부터 다시 하지 않고 중간 어딘가에서 부터 다시 한다.
그러나 ahocorasic algorithm을 이용하면 여러 바늘을 동시에 검색 할 수
있기 때문에 시간 복잡도를 더욱 줄일 수 있다.

## Time Complexity

```
O(N + M + P)
```

`N`은 짚더미 문자열 길이이다.  `M`은 바늘 문자열 길이의 합이다.  `P`은
바늘 문자열 출현의 횟수이다.



# Implementation

* [c++11](/fundamentals/tree/ahocorasic/a.cpp)


# References

* [Aho-Corasick Algorithm for Pattern Searching](https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/)
