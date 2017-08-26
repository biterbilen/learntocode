# Abstract

- separate chaining에 대해 적어본다.

# Implementation

- list를 배열의 형태로 key와 value를 저장하자.
- key, value를 삽입할 때 hash(key)에 해당하는 리스트에 key와 value를
  저장한다.
- key를 검색할때는 hash(key)에 해당하는 리스트를 순회하여 key와 일치하는
  value를 찾는다.

# References

- [separate chaining @ youtube](https://www.youtube.com/watch?v=BwcKHxUYRB4&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=123)
- [separate chaining @ geeksforgeeks](http://www.geeksforgeeks.org/hashing-set-2-separate-chaining/)