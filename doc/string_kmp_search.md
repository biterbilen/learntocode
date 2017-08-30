# Abstract

- knuth morris prat algorithm에 대해 적는다.

# Keyword

- kmp_search(string H, string N), begin, mached, vector<int> pi, get_pi

# Idea

- 건초더미 문자열 H에서 바늘 문자열 N을 찾아보자. N의 partial index인
  pi를 생성한다. pi[i] 는 N[0..i]에서 접두사이고 접미사인 부분
  문자열의 최대 개수가 저장되어 있다.
- H를 0번 문자부터 순회하면서 N이 존재하는지 검사할때 pi를 활용하면
  건너뛰기 검색이 가능하다.

# Implementation

```cpp
```

# Time Complexity

- O(|H|)

# Space Complexity

- 

# References

- [KMP String matching algorithm @ youtube](https://www.youtube.com/watch?v=v82y5TCcBhQ)
