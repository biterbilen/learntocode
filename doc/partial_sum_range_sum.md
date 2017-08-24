# Abstract

- partial sum과 range sum에 대해 적는다.

# partial sum

- 부분합을 미리 만들어 두면 유용하다.
- psum[0] = a[0]             (i == 0)
- psum[i] = psum[i-1] + a[i] (i => 1)

```cpp
std::vector<int> PartialSum(const std::vector<int>& a) {
  std::vector<int> r(a.size());
  r[0] = a[0];
  for (int i = 1; i < a.size(); ++i) {
    r[i] = r[i-1] + a[i];
  }
  return r;
}
```

# range sum

- a 인덱스부터 b 인덱스 까지의 구간합은  psum[b] - psum[a-1]이다.

```cpp
int RangeSum(const std::vector<int>& psum, int a, int b) {
  if ( a == 0)
    return psum[b];
  return psum[b] - psum[a - 1];
}
```