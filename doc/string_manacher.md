# Abstract

특정한 문자열 H가 주어졌을 때 길이가 가장 긴 회문 부분 문자열을 찾는
방법인 manacher's algorithm에 대해 적는다.

# Keyword

```
manacher_search(string H)
```

# Idea

z[i] 배열에 i 를 중심으로 최대 회문 문자열의 반지름을 기록한다. 예를
들어서 문자열 `banana` 의 경우 z 는 `[0, 0, 1, 2, 1, 0]` 과 같다.
문자열 H 의 인덱스 i 를 0부터 하나씩 증가하면서 다음과 같이 반복한다.

지금까지의 z[i] 들중 가장 큰 값을 r에 저장하고 그 때의 index 를 j 라고
하자. j 는 지금까지 발견된 회문 부분 문자열중 가장 큰 것의 중심이다.
만약 i 가 j + r 보다 작거나 같다면 j 를 중심으로 하는 회문 부분 
문자열안에 i 와 대칭인 i' 이 존재 할 것이고 i 를 중심으로 구성되는
회문은 i' 을 중심으로 구성되는 회문보다 길이가 작거나 같을 것이다. 이것을
근거로 i 의 최소 회문 반지름의 길이를 k 라 하고 k 를 하나씩 증가하면서 최대
회문 길이를 구한다.

mancher 는 홀수 길이의 문자열에서만 성립하기 때문에 짝수 문자열이 주어질 때
사이 사이를 . 으로 채워 길이를 홀수로 만든 다음 알고리즘을 적용한다.


# Implementation

[c++11](/fundamentals/string/manacher/)

# Time Complexity

- O(H)

# Space Complexity

- O(H)
