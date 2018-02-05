# Abstract

ahocorasic algorithm에 대해 적는다.

# Idea

짚더미에서 여러개의 바늘을 찾을 때 유용한 알고리즘이다. 여러가지의
바늘들로 [Trie](/doc/tree_trie.md)를 만들고 검색 도중 실패 하면
처음부터 다시 하지 말고 중간 어딘가에서 부터 다시 한다. 여러개의
바늘들을 동시에 검색하기 때문에 바늘1을 찾다가 실패하면 바늘2를 찾을
수도 있다.

예를 들어 다음 그림과 같이 바늘들 `he, she, his, hers` 의 Trie를
구성해 보자.

![](/_img/ahocorasick1.png)

그리고 각 노드들에 대해서 다음 단어가 예상 단어가 아니라면 다른 노드를
찾아가는 failure link를 구성해보자.

![](/_img/ahocorasick2.png)

`shis` 가 짚더미중 일부라고 해보자. `sh` 다음에 `e`가 오지 않고 `i`가
왔으므로 failure link에 의해 `4`노드 대신 `1`노드로 간다. 이후 `is`가
오기 때문에 `his`를 검색 할 수 있다.

KMP 역시 짚더미에서 바늘을 찾을 때 바늘의 partial match table을 만들어
검색중 실패시 처음부터 다시 하지 않고 중간 어딘가에서 부터 다시 한다.
그러나 ahocorasic algorithm을 이용하면 여러 바늘을 동시에 검색 할 수
있기 때문에 시간 복잡도를 더욱 낮출 수 있다.

# Implementation

* [c++11](/fundamentals/tree/ahocorasic/a.cpp)

# Time Complexity

```
O(K + P + M)
```

# References

* [Aho-Corasick Algorithm for Pattern Searching](https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/)
