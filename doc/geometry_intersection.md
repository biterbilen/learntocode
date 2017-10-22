# Abstract

직선과 직선의 교차 선분과 선분의 교차에 대해 정리한다.

# Line Intersection

직선을 한점과 방향 벡터로 표현할 수 있다. 이것을 [직선의 벡터
방정식](http://koc.chunjae.co.kr/Dic/dicDetail.do?idx=22585)이라고
한다.

![](../_img/line_vector_eq.png)

```
직선 g를 지나는 두점 a, b와
직선 f를 지나는 두점 c, d가
주어졌을때 두직선 g와 f의 교차점 x를 구해보자.

먼저 직선의 벡터 방정식을 알아보자.
직선 g위의 무수히 많은 점p 은 
한점 a, 방향 벡터 u, 임의의 실수 t를 이용하여
다음과 같이 표현 가능하다.
p = a + tu
t값을 적당히 설정하여 직선 g의 무수히 많은 점 p를
만들 수 있다는 의미이다. 이것을 직선 g의
벡터 방정식이라고 한다.

이 때 g의 방향벡터와 f의 방향벡터는 다음과 같다.

u = b - a
v = d - c

그러므로 두직선을 벡터 방정식으로 표현하면 각각
a + pu, c + qv 이다.

두직선이 만나는 교차 점은 다음과 같이 표현 할 수 있다.
a + pu = c + qv

이것을 좌표의 x, y 원소 별로 나누어 다음과 같은 연립 방정식을 얻을 수 있다.
a_x + p * u_x = c_x + q * v_x
a_y + p * u_y = c_y + q * v_y

q = (a_x - c_x + p * u_x) / v_x
q = (a_y - c_y + p * u_y) / v_y

(a_x - c_x + p * u_x) / v_x = (a_y - c_y + p * u_y) / v_y
(a_x - c_x + p * u_x) * v_y = (a_y - c_y + p * u_y) * v_x
p * (u_x * v_y - u_y * v_x) = ((c_x - a_x) * vy - (c_y - a_y) * vx)
p = ((c_x - a_x) * v_y - (c_y - a_y) * v_x) / (u_x * v_y - u_y * v_x)
p = ((c - a) × v) / (u × v)

x = a + p * u
x = a + ((c - a) × v) / (u × v) * u
x = a + ((c - a) × (d - c)) / ((b - a) × (d - c)) * (b - a)
```

다음은 언급한 내용을 구현한 것이다.

```cpp
bool line_intersection(vector2 a, vector2 b,
                       vector2 c, vector2 d,
                       vector2& x) {
  double det = (b - a).cross(d - c);
  // in case of pararrel
  if (fabs(det) < EPSLION)
    return false;
  x = a + (b - a) * ((c - a).cross(d - c) / det);
  return true;
}
```

# Segment Intersection


```cpp
```

# Segment Intersection without cross point

```cpp
```


# References

* [직선의 벡터방정식 @ 천재학습백과](http://koc.chunjae.co.kr/Dic/dicDetail.do?idx=22585)
