# Problem

숫자들을 저장한 일차원 배열의 특정 구간에서 최소 값을 구간 트리를
이용하여 찾아보자.

# Segment Tree

N개의 입력 데이터가 있다고 하자. 이것을 구간 트리로 만들어 두면
일정한 범위에 대한 연산을 빠른 시간(`O(lgN)`)에 수행할 수 있다.
구간트리는 complete binary tree이다. 

complete binary tree는 마지막 level를 제외한 모든 level이
채워져 있고 마지막 level의 모든 노드들은 왼쪽으로 채워져 있다.

![](BinaryTree.png)

complete binary tree는 포인터를 이용하는 것보다 일차원 배열로 표현하는
것이 메모리를 더욱 절약 할 수 있다.

루트 노드를 구간트리배열의 1번 노드라고 하면 모든 노드 i의 왼쪽 자손과
오른쪽 자손을 각각 2×i, 2×i+1이라고 할 수 있다.

입력데이터의 개수가 N이라면 구간트리 배열의 크기는 얼마로 해야할까?
입력데이터는 구간 트리의 leaf node에 해당한다. leaf node를 제외한
node들은 구간에 대한 정보를 담고 있다. 구간 트리가 complete binary이기
때문에 leaf node들의 개수는 N보다 크거나 같은 2의 승수이어야
한다. 이것을 `T`라 하면 구간트리 배열의 크기는 다음과 같다.

```
length of segment tree array = T + T - 1
                             = 2T - 1
```

complete binary tree에서 leaf node의 개수가 `T`라면 leaf node보다
레벨이 작은 녀석들의 개수는 `T-1`이다. N보다 크거나 같은 2의 승수를
찾는 것이 번거롭다면 구간트리 배열의 개수를 `4N`으로 해도 좋다.

구간트리를 제작할때 `O(N)`만큼 걸리고 질의할때 `O(lgN)`만큼 걸린다.
하나의 입력 데이터에 대해 여러개의 질의가 있을때 유용하다.

# Idea

이러한 문제를 RMQ (range minimum query) 라고 부른다.

먼저 입력데이터를 구간트리로 제작해야 한다. 구간트리 RMQ는 다음과 같이 구현한다.

```cpp
struct RMQ {
  int m_n;
  std::vector<int> m_rangemin;
  explicit RMQ(const std::vector<int>& v) {
    m_n = v.size();
    m_rangemin.resize(m_n * 4);
    init(v, 0, m_n - 1, 1);
  }

  // vleft: left index of v
  // vright: right index of v
  // rmidx: index of m_rangemin
  int init(const std::vector<int>& v, int vleft, int vright, int rmidx) {
    // base condition
    if (vleft == vright)
      return m_rangemin[rmidx]= v[vleft];

    // recursion
    int vmid = (vleft + vright) / 2;
    int leftmin = init(v, vleft, vmid, rmidx * 2);
    int rightmin = init(v, vmid + 1, vright, rmidx * 2 + 1);

    return m_rangemin[rmidx] = std::min(leftmin, rightmin);
  }

  int query(int vleft, int vright) {
    return query(vleft, vright, 1, 0, m_n - 1);
  }

  // qvleft: query left index of vector
  // qvright: query right index of vector
  // rmidx: range min index
  int query(int qvleft, int qvright, int rmidx,
            int vleft, int vright) {
    // base condition
    if (qvright < vleft || vright < qvleft)
      return MAX_INT;
    if (qvleft <= vleft && vright <= qvright)
      return m_rangemin[rmidx];

    // recursion
    int vmid = (vleft + vright) / 2;
    return std::min(query(qvleft, qvright, rmidx * 2, vleft, vmid),
                    query(qvleft, qvright, rmidx * 2 + 1, vmid + 1, vright));
  }

  int update(int vidx, int newvalue) {
    return update(vidx, newvalue, 1, 0, m_n - 1);
  }

  int update(int vidx, int newvalue, int rmidx, int vleft, int vright) {
    // base condition
    // vidx is out of range between vleft and vright
    if (vidx < vleft || vidx > vright)
      return m_rangemin[rmidx];
    if (vleft == vright)
      return m_rangemin[rmidx] = newvalue;

    // recursion
    int vmid = (vleft + vright) / 2;
    return m_rangemin[rmidx] = std::min(
        update(vidx, newvalue, rmidx * 2, vleft, vmid),
        update(vidx, newvalue, rmidx * 2 + 1, vmid + 1, vright));
  }
};
```

# Implementation

[c++11](../fundamentals/tree/rmq/a.cpp)

# Time Complexity

```
O(N)   : segment tree build
O(lgN) : range minimum query 
```

# References

[세그먼트트리 @ acmicpc.net](https://www.acmicpc.net/blog/view/9)
