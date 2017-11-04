# Problem

https://algospot.com/judge/problem/read/POTION

# Idea

병의 개수를 `n`이라고 하자.  각 병의 제조 가능한 레시피의 양을
`r_{i}'라고 하자.  각 병에 미리 들어있는 양을 `p_{i}`라고 하자.  모든
병을 순회하면서 `p_{i} / r_{i}`를 계산하고 이것을 `l_{i}`라고 하자.
`l_{i}`중 가장 큰 값(실수)을 선택하고 이것을 `X`라고 하자.  `X`의
ceil값이 최소로 제조 가능한 병의 개수이고 이것을 Y라고 하자.

각 병을 순회하면서 `(p_{i} + a_{i}) / r_{i} = Y`가 되도록
`a_{i}`를 찾아내면 된다. 이때 `a_{i} = r_{i} * Y - p_{i}`
가 된다.

# Implementation

```cpp
```

# Time Complexity

O(N)
