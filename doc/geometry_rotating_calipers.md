# Abstract

convex polygon (볼록 다각형) 을 구성하는 점들의 거리중 가장 먼 것을
볼록 다각형의 지름이라고 한다. 회전하는 칼리퍼스를 이용하여 볼록 다각형의
지름을 구해보자.

캘리퍼스는 컴퍼스와 매우 비슷한 도구로 작은 치수를 잴때 쓴다.

# Idea

다격형을 구성하는 모든 점들중 가장 왼쪽 것과 가장 오른쪽 것을 l,
r이라고 하자. l을 지나는 수직선, r을 지나는 수직선을 두개 그리자.
준으로 캘리퍼스를 돌려가며 가장 길이가 큰
지름을 찾는다. 

l을 하나 우측으로 이동한 점의 위치를 l+1이라 하고
r을 하나 좌측으로 이동한 점의 위치를 r+1이라 하자.
선분 l-(l+1)과 



# Implementation

[src](../fundamentals/computationalgeometry/rotatingcalipers/a.cpp)

# Time Complexity

O(N)

# References

* [캘리퍼스 @ 위키피디아](https://ko.wikipedia.org/wiki/%EC%BA%98%EB%A6%AC%ED%8D%BC%EC%8A%A4)
