# Abstract

- 동적으로 배열을 늘리는 리스트이다. 배열은 랜덤억세스가 가능해서
  검색시간이 O(1)이다.

# Implementation

- 새로운 원소가 삽입될때 기존의 배열이 부족하다면 배열의 크기를
  증가하자.

```cpp
int darray_size = 0;
int darray_capacity = 1024;
int darray_capacity_delta = 1024;
int* darray;

void DarrayPush(int new_value) {
  // if darray is fulll reallocate memory
  if (darray_size == darray_capacity) {
    int new_capacity = darray_capacity + darray_capacity_delta;
    int* new_arr = new int[new_capacity];
    // copy legacy array
    for (int i = 0; i < darray_size; ++i) {
      new_arr[i] = darray[i];
    }
    // delete legacy array, change to new array
    if (darray)
      delete [] darray;
    darray = new_arr;
    darray_capacity = new_capacity;
  }
  // push new_value
  darray[darray_size++] = new_value;
}

int main() {
  darray = new int[darray_capacity];
  DarrayPush(3);
  return 0;
}
```