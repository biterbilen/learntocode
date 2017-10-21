# Abstract

직선과 직선의 교차 선분과 선분의 교차에 대해 정리한다.

# Line Intersection

직선을 한점과 방향 벡터로 표현할 수 있다. 이것을 [직선의 벡터
방정식](http://koc.chunjae.co.kr/Dic/dicDetail.do?idx=22585)이라고
한다.

![](../_img/line_vector_eq.png)

```
직선 g의 벡터 방정식을 구하여 보자.

직선 g위의 무수히 많은 점들은 
한점 a, 방향 벡터 u, 임의의 실수 t를 이용하여
다음과 같이 표현 가능하다.
p = a + tu
t값을 적당히 설정하여 직선 g의 무수히 많은 점 p를
만들 수 있다는 의미이다. 이것을 직선 g의
벡터 방정식이라고 한다.

두직선을 a + pb, c + qd라고 하자.
(a, c는 점 c, d는 방향 벡터, p, q는 실수)

두직선이 만나는 교차 점은 다음과 같이 표현 할 수 있다.
a + pb = c + qd

이것을 x, y별로 나누어 다음과 같은 연릭 방정식을 얻을 수 있다.
a_x + p * b_x = c_x + q * d_x
a_y + p * b_y = c_y + q * d_y

q = (a_x - c_x + p * b_x) / d_x
q = (a_y - c_y + p * b_y) / d_y

(a_x - c_x + p * b_x) / d_x = (a_y - c_y + p * b_y) / d_y
(a_x - c_x + p * b_x) * d_y = (a_y - c_y + p * b_y) * d_x
p * (b_x * d_y - b_y * d_x) = ((c_x - a_x) * dy - (c_y - a_y) * dx)
p = ((c_x - a_x) * d_y - (c_y - a_y) * d_x) / (b_x * d_y - b_y * d_x)
p = ((c - a) × d) / (b × d)

두직선이 만나는 교차점을 x라고 하자.
x = a + p * b
x = a + ((c - a) × d) / (b × d) * b
```

다음은 언급한 내용을 구현한 것이다.
b는 왜 b-a일까? d는 왜 d-c일까?
a는 왜 a일까? b는 왜 b-a일까?

```cpp
bool line_intersection(vector2 a, vector2 b,
                       vector2 c, vector2 d,
                       vector2& x) {
  // why b is b-a, d is d-c???
  double det = (b - a).cross(d - c);
  // in case of pararrel
  if (fabs(det) < EPSLION)
    return false;
  // why a is a ???
  // why b is b-a ???
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
