# Abstract

펜윅 트리는 주로 구간 합을 빠르게 구하는 곳에 유용하다.
구간 트리 역시 주로 구간 합을 빠르게 구하는 곳에 이용한다. 
하지만 펜윅 트리가 구간 트리보다 공간 복잡도가 더욱 낮다.

# Data Structure Fenwick Tree

다음은 16개의 입력 데이터에 대한 구간 트리이다.

```
[0                                                           15]
[0                            7][8                           15]
[0            3][4            7][8           11][12          15]
[0    1][2    3][4    5][6    7][8    9][10  11][12  13][14  15]
[ 0][ 1][ 2][ 3][ 4][ 5][ 6][ 7][ 8][ 9][10][11][12][13][14][15]
```

다음은 위의 구간 트리에서 중복된 노드들을 지우자. 공간 복잡도가
훨씬 낮아졌다. 

```
[0                                                           15]
[0                            7]
[0            3]                [8           11]
[0    1]        [4    5]        [8    9]        [12  13]
[ 0]    [ 2]    [ 4]    [ 6]    [ 8]    [10]    [12]    [14]
```

구간 트리와 비슷하게 남겨진 노드들을 배열을 이용해 다음과
같이 저장하자. 

```
vector<int> tree;
```

이때 모든 노드들의 인덱스에 1을 더하고 구간의 맨 오른쪽 숫자를
이진수로 표현해 보자. 

![](../_img/fenwick.png)

위의 그림은 펜윅 트리를 표현한 것이다. 구간별 가장 오른쪽 숫자를
이진수로 표기했을때 규칙을 발견할 수 있고 이것을 이용해서 `Add` 와
`Sum` 을 구현한다.

# Algorithm Sum

## Idea

![](../_img/fenwick.png)

위 그림에서 `Sum(7)` 을 구해 보자. `tree[7] + tree[6] + tree[4]` 를
수행해야 한다. 이때 `7, 6, 4`를 이진수로 표현하면 `111, 110, 100`이다.
하나씩 감소하는 규칙을 발견 할 수 있고 다음과 같이 `pos` 에
관한 식을 만들어 낼 수 있다.

```
pos = pos & (pos - 1)
```

순회 할때 마다 `tree[pos]` 를 모두 합하면 답이 된다. 구간 `[a, b]`의
구간합은 `Fenwick::Sum(b) - Fenwick::Sum(a-1)`를 이용해서 구한다.

## Time Complexity

```
O(lgN)
```

# Algorithm Add

## Idea

![](../_img/fenwick.png)

위 그림에서 `Add(7, 3)`을 수행해보자. `tree[7], tree[8], tree[16]` 을
갱신해야 한다. 이때 `7, 8, 16` 을 이진 수로 표현하면 `111, 1000,
10000` 이다. `0` 이 하나씩 늘어나는 규칙을 발견 할 수 있고 다음과 같이
`pos` 에 관한 식을 만들어 낼 수 있다.

```
pos = pos + (pos & -pos)
```

`pos` 를 순회 하면서 `tree[pos]` 에 `3` 을 더한다.

## Time Complexity

```
O(lgN)
```

# Implementation

* [c++11](/fundamentals/tree/fenwick/a.cpp)

# References

* [Binary Indexed Tree or Fenwick Tree @ geeksforgeeks](https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)
