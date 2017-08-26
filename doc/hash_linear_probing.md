# Abstract

- linear probing에 대해 적는다.

# Idea

- 배열에 key와 value를 저장한다.

- key와 value를 삽입할때 hash(key)에 이미 value가 있다면 충돌이 발생한
  것이므로 충돌이 발생한 공간의 이웃들중 빈 공간으로 저장한다. 이때
  value와 함께 key도 저장한다.
- key를 검색할때는 hash(key)에 해당하는 공간부터 충돌시 저장하는 방향으로
  선형검색하여 key와 일치하는 value를 찾는다.

# References

- [linear probing @ youtube](https://www.youtube.com/watch?v=BwcKHxUYRB4&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=123)
- [linear probing @ geeksforgeeks](http://www.geeksforgeeks.org/hashing-set-3-open-addressing/)