# Problem

https://algospot.com/judge/problem/read/POTION

# Idea

병의 개수를 `n`이라고 하자.  각 병의 제조 가능한 레시피의 양을
`r_{i}'라고 하자.  각 병에 미리 들어있는 양을 `p_{i}`라고 하자.  모든
병을 순회하면서 `p_{i} / r_{i}`를 계산하고 이것을 `l_{i}`라고 하자.

`l_{i}`들 중 가장 큰 값(유리수)을 선택하고 이것을 `Y`라고 하자.
따라서 모든 `l_{i}` 는 Y와 같아야 한다. 이때 Y는 유리수 이기 때문에 `Y
= a / b`이다. a, b는 정수이다.


각 병을 순회하면서 `(p_{i} + a_{i}) / r_{i} = Y`가 되도록
`a_{i}`를 찾아내면 된다. 이때 `a_{i} = r_{i} * Y - p_{i}`
가 된다.

# Implementation

```cpp
```

# Time Complexity

O(N)
