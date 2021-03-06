# Abstract

convex polygon (볼록 다각형) 을 구성하는 점들의 거리중 가장 먼 것을
볼록 다각형의 지름이라고 한다. 회전하는 칼리퍼스를 이용하여 볼록 다각형의
지름을 구해보자.

캘리퍼스는 컴퍼스와 매우 비슷한 도구로 작은 치수를 잴때 쓴다.

# Idea

![](../_img/rotating_calipers.png)

다각형의 모든 점들을 짝을 지어 거리를 잰다면 쉽게 다각형의 지름을 찾을
수 있다. 하지만 시간 복잡도는 O(N^2)이기 때문에 아쉽다. 모든 점들의
짝을 검색하는 것보다는 그럴 법한 점들을 검색한다면 훨씬 효율적일
것이다.  두개의 캘리퍼스를 이용하여 다각형의 지름이 될만한
점들만 검색의 대상으로 하여 훨씬 효율적으로 해결해 보자.

다각형을 구성하는 모든 점들중 가장 왼쪽 것과 가장 오른쪽 것을 l,
r이라고 하자. l을 지나는 수직선, r을 지나는 수직선을 두개 그리자.
이것을 각각 l 캘리퍼스, r 캘리퍼스라고 하자. 두개의 캘리퍼스는 항상
평행하도록 한다.

다각형을 구성하는 선분을 순회 하면서 두개의 캘리퍼스중 하나를 지나도록
하자. 캘리퍼스를 돌려가며 가장 길이가 큰 지름을 찾는다. 

l을 시계 방향 으로 하나 이동한 점의 위치를 l+1이라 하고 r을 하나 시계
방향 으로 하나 이동한 점의 위치를 r+1이라 하자.  선분 l-(l+1)과
l캘리퍼스가 이루는 사이각을 θ_{l}라 하고 선분 r-(r+1)과 r캘리퍼스가
이루는 사이각을 θ_{r} 라 하자.  사이각의 값이 작은 곳의 선분을
가까운 캘리퍼스를 지나도록 한다. 언급한 절차를 최초 l이 최초 r이 되거나
최초 r이 최초 l이 될때까지 반복한다.

# Implementation

[c++11](../fundamentals/computationalgeometry/rotatingcalipers/a.cpp)

# Time Complexity

O(N)

# References

* [캘리퍼스 @ 위키피디아](https://ko.wikipedia.org/wiki/%EC%BA%98%EB%A6%AC%ED%8D%BC%EC%8A%A4)
* [TFOSS - Fossil in the Ice @ spoj](http://www.spoj.com/problems/TFOSS/)
* [Rober Hood @ kattis](https://open.kattis.com/problems/roberthood)
