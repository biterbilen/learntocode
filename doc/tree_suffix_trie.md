# Abstract

접미사들의 배열을 트리 형태로 저장한 suffix trie에 대해 정리한다.

# Data Structure Suffix Trie

접미사들의 배열을 이용하면 문자열 검색 문제를 쉽게 해결 할 수 있다.
예를 들어서 'banana' 의 접미사들은 다음과 같다.

```
banana\0
anana\0
nana\0
ana\0
na\0
a\0
\0
```

이제 이것들을 [trie](/doc/tree_trie.md)에 저장하면 다음과 같다.

![](/_img/suffixtrie.png)


# Algorithm Insert

[trie](/doc/tree_trie.md)의 Insert와 같다.

# Algorithm Find

[trie](/doc/tree_trie.md)의 Find와 같다.

# Implementation

* [c++](/fundamentals/tree/suffixtrie/a.cpp)
