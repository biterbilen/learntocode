# Abstract

Trie에 대해 정리한다.

# Data Structure Trie

![](/_img/trie.png)

Trie는 문자열 검색을 쉽게 하기 위한 트리 형태의 자료구조이다.  트리의
각 노드는 TrieNode라고 정의하고 다음과 같은 두가지 멤버 변수를 갖는다.
하나의 TrieNode는 단어 한 글자에 대응된다.

```
TrieNode* children[ALPHABETS];
bool terminal;
```

영문자의 종류는 26가지 이므로 children은 크기가 26개인 `TrieNode*`의
배열이다. terminal은 TrieNode가 단어의 마지막 글자인지 여부이다.  

포인터는 64-bit system에서 8byte이다. 하나의 TrieNode는 26개의
`TrieNode*`를 자식으로 갖는 형태이기 때문에 `8 * 26 = 208`바이트가
필요하다. 

하나의 TrieNode를 표현하는데 약 200바이트가 필요하다고 가정해보자.
Trie에 저장할 문자열들의 합이 1백만 일때 약 200MB(`1,000,000 * 200 =
200,000,000 bytes`)가 필요하다.  메모리가 너무 많이 필요하다. 문자열의
개수가 얼마 되지 않을때 만 사용 가능한 자료 구조이다.

# Algorithm Insert

## Idea

단어를 입력 받아 재귀 적으로 TrieNode를 생성한다. 부분 문제를 다음과 
같이 정의하자.

```
Insert(const char* key)
```

# Algroithm Find

## Idea

단어를 입력 받아 재귀 적으로 탐색 한다. 부분 문제를 다음과 같이 정의하자.

```
TrieNode* Find(const char* key)
```

# Implementation

* [c++11](/fundamentals/tree/trie/a.cpp)

# Keywords

```
TrieNode, children, terminal, insert, find
```

# References

* [trie video @ youtube](https://www.youtube.com/watch?v=aiy-uY8OB8g) 
* [trie pdf](https://raw.githubusercontent.com/iamslash/dsalgorithm/master/_pdf/trie.pdf)
