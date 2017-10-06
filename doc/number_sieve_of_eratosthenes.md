# Abstract

에라토스테네스의 체에 대해 적는다.

# Idea

2 부터 n까지의 모든 숫자를 순회하면서 소수가 아닌 녀석들을
제거한다. 이러한 과정을 n까지 수행하고 나면 남은 수들은 소수가 된다. 이때
제거되는 숫자들은 합성수이다. 임의의 합성수 m을 p * q로 표현해보자.
p는 항상 sqrt(n)보다 작거나 같고 q는 sqrt(n)보다 크거나 같다.
m을 q x p로 표현하는 경우는 고려대상이 아니다. p * q 통해서 이미 제거되기
때문이다.  따라서 p 에 해당하는 i는 2부터 sqrt(n) 까지만 살펴보면
된다.

예를 들어서 n이 100일때 p가 10이면 q는 10이다. 또한 p가 20인 경우는
q가 2이다. 이때 20 * 2는 2 * 20과 같고 p가 2인 경우는 이미
처리되었기 때문에 p가 20인 경우는 고려대상이 아니다.

i가 정해지면 i의 배수이면서 n보다 작거나 같은 합성수 z를 만들어야
한다. 이때 z는 i * x로 표현할 수 있다. x는 2보다 크거나 같다고
생각할 수 있지만 i가 2보다 크다면 2는 고려대상이 아니다. 만약 x가
i보다 작다면 x * i는 이미 처리되었기 때문이다.

예를 들어서 i가 10일때 x는 2이라고 가정해보자. z는 10 * 2 로 표현할
수 있다. 이것은 2 * 10과 같고 i가 2일때 이미 처리 되었기 때문에
고려할 대상이 아니다.

# Implementation

```cpp
#define MAX_N 987654321
unsigned char SIEVE[(MAX_N+7)/8];
// char에 8개 숫자의 소수 여부를 저장하기 위해
// 8을 이용해서 나눈 몫과 나머지를 이용하여
// 인덱싱 한다.
// k >> 3 은 k를 8로 나눈 몫이다.
// 1 << (k & 7) 은 k를 8로 나눈 나머지다.
inline bool is_prime(int k) {
    return SIEVE[k >> 3] & (1 << (k & 7));
}
inline set_composite(int k) {
    return SIEVE[k >> 3] &= ~(1 << (k & 7));
}
void eratos_thenes(int n) {
    memset(SIEVE, 0xFF, sizeof(SIEVE));
    set_composite(0);
    set_composite(1);
    int sqrtn = int(sqrt(n));
    for (int i = 2; i <= sqrtn; ++i) {
        if (is_prime(i)) {
            for (int j = i * i; j <= n; j+= i) {
                set_composite(j);
            }
        }
    }
}
```
