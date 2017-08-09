# abstract

- 허프만 코드에 대해 적어본다.
- [허프만 압축 알고리즘 강좌](https://www.youtube.com/watch?v=haXz9MEOGbo)

# idea

- 발생빈도가 가장 낮은 두 문자를 선택해서 하나로 합치자.
- 왼쪽은 빈도수가 낮고 오른쪽은 빈도수가 높다.
- 빈도수가 같은 것 중에서는 작은 것을 우선적으로 연결한다.
- 트리가 생성되면 root부터 왼쪽은 0을 오른쪽은 1을 부여한다.

# example

- APPLEBANANAMANGOJUICE
- A(5), B(1), C(1), E(2), G(1), I(1), J(1), L(1), M(1), N(3), O(1),
  P(2), U(1)
- 트리의 leaf node는 root부터 edge를 따라 숫자로 코딩 된다.
- 결과적으로 원래 21 * 8 = 168 bit가 필요하지만 huffman code는 51 bit으로 압축이 가능하다.
