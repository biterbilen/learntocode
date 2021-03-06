# Problem

입력 데이터의 일정한 범위에서 가장 작은 두개의 값을 찾아라.

# Idea

한개의 입력 데이터에 대해 다수의 질의가 존재하는 모델이다.  segment
tree를 하나 제작하고 질의 한다면 `O(lnN)`으로 질의를 수행할 수 있다.

[RMQ](/doc/tree_rmq.md)를 참고하여 segment tree를 제작하자.
이때 가장 작은 두수를 `RangeItem`으로 정의하고 `rangeitems`는
`RangeItem`의 vector로 정의하자.

leaf node의 경우 `no1`을 leaf node의 숫자로 채우고 `no2`는 아주 큰
수를 채운다. `no2`는 최소값 경쟁에서 쉽게 제외 시킬 수 있다.

[RMQ](/doc/tree_rmq.md)와 다르게 `min`대신 `merge`를 사용한다.
`merge`재귀 적으로 두 노드를 합하여 `no1`, `no2`를 다시 계산한다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)   : build segment tree
O(lgN) : query
```

# Space Complexity

```
O(N) : segment tree array
```

# References

[Range Minimum Query, For Top 2 Min Elements in single range](http://codeforces.com/blog/entry/15924)

```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (int) 1e6;
const int INF = (int) 1e9 + 7;
 
struct node {
    int fmin, smin;
    node(int x = 0, int y = 0) {
        fmin = x;
        smin = y;
    }
};
 
node t[N];
 
int n;
int a[N];
 
node merge(node a, node b) {
    node c;
    if (a.fmin < b.fmin) {
        c.fmin = a.fmin;
        c.smin = min(a.smin, b.fmin);
    }
    else {
        c.fmin = b.fmin;
        c.smin = min(b.smin, a.fmin);
    }
    return c;
}
 
void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = node(a[tl], INF);
    else {
        int m = (tl + tr) / 2;
        build(v + v, tl, m);
        build(v + v + 1, m + 1, tr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
}
 
node get(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return node(INF, INF);
    else if (l <= tl && tr <= r) return t[v];
    else {
        int m = (tl + tr) / 2;
        return merge(get(v + v, tl, m, l, r), get(v + v + 1, m + 1, tr, l, r));
    }
}
 
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) t[v] = node(val, INF);
    else {
        int m = (tl + tr) / 2;
        if (pos <= m) upd(v + v, tl, m, pos, val);
        else upd(v + v, m + 1, tr, pos, val);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
 
    build(1, 1, n);
 
    int m;
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        node res = get(1, 1, n, l, r);
        printf("%d %d\n", res.fmin, res.smin);
    }
    return 0;
}
```
