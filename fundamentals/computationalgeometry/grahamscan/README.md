# Abstract

convex hull algorithm들중 graham scan algorithm에 대해 정리한다.

# Idea

모든 점들을 y값의 오름차순으로 정렬하고 가장 작은 y값을 갖는 점을
p라고 하자. 정렬된 점들을 p와 연결하여 만들어진 선분들의 극각도의
오름차순으로 다시 정렬한다. 정렬된 점들의 첫번째 점은 convex hull이
명백하다. 첫번째 두번째 세번째 점을 가각 a, b, c라고 할때
ccw(a, b, c)가 0보다 작으면 b는 convex hull이 아니다.

# Implementation

```cpp
```

# Time Complexity

O(NlgN)

# References

* [6. convex hull @ algorithm](https://www.youtube.com/watch?v=-HuIMvYROls&list=PLe-ggMe31CTe_5WhGV0F--7CK8MoRUqBd&index=6)
* [Convex Hull | Set 2 (Graham Scan) @ geeksforgeeks](http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/)
