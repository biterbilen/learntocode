# Abstract

나머지 연산자 %에 대해 적는다.

# Add

두 정수 a + b를 M으로 나눈 나머지를 구해보자.

```
a = xM + a'
b = yM + b'
a + b = (x + y)M + (a' + b')
a + b를 M으로 나눈 나머지는 a' + b'을 M으로 나눈 나머지와 같다.
(a + b) % M = ((a % M) + (b % M)) % M
```

A[]에 담겨있는 정수들을 모두 더하고 마지막 여덟자리를 구해 보자.  앞서
언급한 %의 덧셈 성질을 활용해 보자. A[]를 차례대로 순회하면서 각
원소에 대해 10^{8}으로 나눈 후 나머지를 더해간다. 두수를 더할 경우 다시
10^8으로 나누어 나머지를 다음 덧셈에 이용한다.

다음 코드를 참고하자. A[]는 64bit의 정수들이 담겨
있지만 32bit정수를 이용하여 10^8으로 나눈 나머지를
문제 없이 구할 수 있다.

```c
long A[N];
int r = 0;

for (int i = 0; i < N; ++i) {
  r += A[i] % sizeof(int);
  r %= sizeof(int);
}

```

# Sub

```
(a - b) % M = ((a % M) - (b % M)) % M```
```

# Mul

```
(a X b) % M = ((a % M) X (b % M)) % M```
```

# Div

* [나머지 연산의 곱셈 역원 @ acmicpc.net](https://www.acmicpc.net/blog/view/29)
* [나머지 연산 내 곱셈 역원](http://zetacode.com/math/2016/04/22/modular-multiplicative-inverse.html)

앞서 언급한 바와 같이 나머지 연산자는 덧셈, 뺄셈, 곱셈에 대해서 분배
법칙이 성립한다. 하지만 나눗셈에 대해서는 그렇지 않다.  덧셈, 뺄셈,
곱셈은 정수에 닫혀있지만 나눗셈은 실수에 닫혀있기 때문이다. (a / b
는 정수라는 보장이 없다.)

그래서 나눗셈을 곱셈으로 표현해서 해결해 보자.

```
(a / b) % M = (a * b^{-1}) % M
            = ((a % M) * (b^{-1} % M)) % M
b^{-1} % M 을 구할 수 있으면 해결된다.

첫번째 방법은 페르마의 소정리(Fermat's Little Theorem)를 이용한 것이다.

페르마의 소정리는 다음과 같다.
정수 a, p가 서로소일때 
a^{p - 1} % p = 1

양변에 a_{-1}를 곱하자.
a^{p - 1} * a_{-1} % p = 1 * a^{-1} % p 
a^{-1} % p = a^{p - 2} % p

따라서 b^{-1} % M = b^{M - 2} % M
(a / b) % M = ((a % M) * (b^{M - 2} % M)) % M
단 b와 M은 서로소이어야 한다.

두번째 방법은 확장 유클리드 호제법 (Extended Euclidean Algorithm)을 이용한 것이다.

확장 유클리드 호제법은 다음과 같다.
정수 a, b에 대해 아래식을 만족하는 정수 x, y가 존재한다.
gcd(a, b) = ax + by

b * b^{-1} ≡ 1 (mod M)을 만족하는 b^{-1}을 찾아야 한다.
이때 b와 M은 서로소이어야 한다.
b^{-1}를 x라고 하자.
bx % M = 1
bx + My       = gcd(b, M)
(bx + My) % M = ((bx % M) + (My % M)) % M = ((bx % M) + 0) % M
              = gcd(b, M) % M
              = 1 % M
```

다음은 확장 유클리드 알고리즘을 이용하여 나머지 연산자에 대한 곱셈의 역원을 구현한 것이다.

```python
def xgcd(a, b):
	if b == 0:
		return [1, 0, a]
	x, y, d = xgcd(b, a % b)
	return [y, x - (a // b) * y, d]

def inv(a, M):
	x, y, d = xgcd(a, M)
	return x
```
