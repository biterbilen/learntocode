# Problem

[Next Permutation @ leetcode](https://leetcode.com/problems/next-permutation/description/)

# Idea

`1 2 3 4 5` 초기 수열이라 하자. 수열이 모두 오름차순으로 정렬되어
있다면 가장 처음 순열이다. 다음 것은 가장 오른쪽 두 자리를 바꾼
것이다.  즉 `1 2 3 5 4` 이다.

만약 `5 4 3 2 1` 처럼 수열이 내림차순이라고 해보자. 이것은 가장 마지막
순열이기 때문에 다음 것은 `1 2 3 4 5` 이다.

그외의 경우를 생각해 보자. 가장 오른쪽 자리에서 왼쪽 자리 방향으로
탐색을 해봤을 때 모두 오름차순으로 정렬되어 있다면 다음 순열은 초기
수열과 같다. 오른차순의 의미는 다음 순열이 없다는 의미와 같다. 그러나
오름차순이 아닌 숫자가 나타난다면 그 숫자부터 숫자를 조작하여 다음
순열을 만들어 낼 수 있다.

예를 들어 `1 2 4 5 3` 을 살펴 보자. 우리는 직관 적으로 다음 순열이 `1
2 5 3 4` 임을 알 수 있다. 가장 오른쪽 숫자 부터 탐색 하다 보면
오름차순을 벗어난 숫자 `4` 를 만난다. `4` 의 오른쪽 수열을 `r` 라고
부르자. `r` 는 오른쪽부터 시작해서 왼쪽으로 오름차순이기 때문에 `r` 만
따져봤을 때 마지막 순열이다. 그리고 `r` 의 숫자들중 반드시 `4` 보다 큰
값이 존재한다. 그 다음 `4` 다음으로 큰 수를 `r` 에서 찾아내어 `4` 와
교체 해야 한다.  그리고 `4` 를 포함한 `r` 를 왼쪽 부터 오름차순으로
만들어야 한다.  왼쪽부터 오른쪽으로 오름차순의 의미는 순열의 시작이기
때문이다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)
```

# Space Complexity

```
O(1)
```
