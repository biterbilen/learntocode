# Abstract

폴리곤 클리핑 문제를 해결하는 알고리즘 중 하나인 서더랜드 호지맨
알고리즘을 정리한다.

# Idea

클리핑을 수행하는 도형(C)과 클리핑의 대상이 되는 도형(P)의 두 점들(v1,
v2)을 이용해 다음과 같이 4가지 경우를 만들어낼 수 있다.

* 선분 (v1, v2) 에서 v1, v2 가 C의 외부에 있는 경우
* 선분 (v1, v2) 에서 v2만 C의 내부에 있는 경우 교점 v1'와 v2를 저장
* 선분 (v1, v2) 에서 v1, v2 가 C의 내부에 있는 경우 v2를 저장
* 선분 (v1, v2) 중 v1만 C의 내부에 있는 경우 교점 v2'를 저장

# Implementation

[src](../fundamentals/computationalgeometry/sutherland/a.cpp)

# Time Complexity

# References

* [Polygon Clipping | Sutherland–Hodgman Algorithm @ geeksforgeeks](http://www.geeksforgeeks.org/polygon-clipping-sutherland-hodgman-algorithm-please-change-bmp-images-jpeg-png/)
* [Sutherland-Hodgman Polygon Clipping Algorithm @ youtube](https://www.youtube.com/watch?v=S091lKYWbSs)
