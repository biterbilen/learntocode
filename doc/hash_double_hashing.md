# Abstract

- double hashing에 대해 적는다.

# Idea

- hash를 배열의 형태로 key와 value를 저장하자.
- key, value를 삽입할 때 hash(key)에 해당하는 hash에
  다시 hash(key)에 해당하는 key, value를 저장한다.

# Implementation

```cpp
DoubleHash(data) {
  index = hash_function(data);
  while(hash_table(index) is not empty)
    index = secondary_hash(data);
  // do something
}
```