# Abstract

소인수 분해에 대해 적어본다.

# Idea

특정 숫자 n을 p x q로 표현해 보자. 이때 p는 소수이다. p의 후보는 2부터
sqrt(n)까지의 소수이다. p는 2이후로 짝수가 될 수 없다.  p가 2일때 이미
소인수 분해 되어 버리기 때문이다.

# Implementation

```cpp
vector<int> factor_simple(int n) {
    vector<int> r;
    int sqrtn = sqrt(n);
    for (int div = 2; div <= sqrtn; ++div) {
        while (n % div == 0) {
            n /= div;
            r.push_back(div);
        }
    }
    if (n > 1)
      r.push_back(n);
    return r;
}
```
