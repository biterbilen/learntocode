# Abstract

suffix tree에 대해 적는다.

# Data Structure Suffix Tree

suffix tree는 suffix trie보다 메모리를 덜 사용한다.

예를 들어 `banana`의 경우 접미사들은 다음과 같다.

```
banana\0
anana\0
nana\0
ana\0
na\0
a\0
\0
```

위의 접미사들을 이용하여 suffix trie를 구성하면 다음과 같다.

![](/_img/suffixtrie.png)

한 줄로 늘어선 노드들을 노드 하나로 압축하여 suffix tree를 구성하면
다음과 같다.

![](/_img/suffixtree.png)

suffix tree가 suffix trie에 비해 더욱 적은 노드들을 사용한다. 그러나
suffix tree의 구현이 복잡하기 때문에 접미사들을 활용하여 문자열 검색
문제를 해결해야 할 경우는 차라리 [suffix
array](/doc/string_suffix_array.md)를 사용하자.

# References

* [Pattern Searching | Set 8 (Suffix Tree Introduction)](https://www.geeksforgeeks.org/pattern-searching-set-8-suffix-tree-introduction/)
