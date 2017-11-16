# Abstract

평면 스위핑 혹은 라인 스위핑에 대해 알아보자.  평면을 세로로 수직선을
여러개 그어서 문제를 해결하는 방법이다. 주로 직사각형들의 합집합에
해당하는 넓이의 합, 직사각형들의 교집합에 해당하는 넓이의 합, 교차하는
선분이 있는지 검사할때 이용한다.

# Problem. Area of rectangular union (직사각형 합집합의 면적)

## Idea

사각형의 데이터를 왼쪽 아래점(LBP, left bottom point)과 오른쪽
위점(RTP, right top point)을 이용해서 입력 받자.  하나의 사각형은 LBP,
RTP 와 같이 두개의 점으로 표현된다.

모든 점들을 x를 기준으로 리스트 A에 담고 y를 기준으로 리스트 B에
담는다.  이때 두 리스트를 모아 놓고 x좌표 혹은 y좌표를 기준으로
오름차순으로 정렬한다. 리스트 A의 첫번째 부터 순회 하면서 다음
점까지의 x축 거리와 y축 거리를 얻어내면 부분 넓이를 얻을 수 있다.  이
것들을 모두 더하면 모든 사각형들의 합집합의 넓이에 해당한다.

예를 다음과 같은 세종류의 사각형이 있다고 하자.

```
 (0, 0), (2, 2)
 (1, 0), (3, 3)
(-1, 1), (2, 4)
```

![](../_img/union_area_ex1.png)

위 그림에서 표시된 순서 대로 부분 넓이를 구하고 전체 넓이를 구할 수 있다.

## Implementation

[src](../fundamentals/computationalgeometry/unionarea/a.cpp)

## Time Complexity

O(N^2)

# Problem. Width of polygon intersection (다각형 교집합의 넓이)

## Idea

## Implementation

[src](../fundamentals/computationalgeometry/interarea/a.cpp)

## Time Complexity

# Problem. Intersecting lines (교차하는 선분들)

## Idea

## Implementation

[src](../fundamentals/computationalgeometry/interlines/a.cpp)

## Time Complexity

## References

* [Given n line segments, find if any two segments intersect @ geeksforgeeks](http://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/)
