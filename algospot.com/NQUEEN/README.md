# Problem

[NQUEEN](https://algospot.com/judge/problem/read/NQUEEN)

# backtracking

## Idea

```
o...
....
....
....
```

N을 4라고 가정하자. `0,0`부터 queen을 놓아보자. 0행은 이미 queen이
위치하여 있으므로 1행의 ?열에 queen을 놓을 수 있다. 1행에 queen이
놓여지면 2행의 ?에 queen을 놓을 수 있다. 두행의 경우를 살펴보니
재귀적으로 해결 할 수 있을 것 같다. 

```
.o..
....
....
....
```

그렇게 하여 4행까지 queen을 위치하면 다시 처음으로 돌아와 `0,1`부터
위의 과정을 반복한다. `0,1`에 queen을 놓고 재귀적으로 반복한 다음 `0,1`에서
queen을 제거하고 `0,2`에 queen을 다시 놓고 재귀적으로 반복한다.
이것은 backtracking 전략과 같다.

## Implementation

[c++11](a.cpp)

## Time Complexity

```
O(N^N)
```

# backtracking with bitmask

## Idea

## Implementation

[c++11](a.cpp)

## Time Complexity

```
O(N^N)
```
