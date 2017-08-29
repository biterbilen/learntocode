# Abstract

- 소박한 문자열 검색 방법에 대해 적는다.

# Idea

- 건초더미의 처음부터 차례대로 바늘이 존재하는지 검색해보자. Brute
  Force전략이다.

# Time Complexity

- O(N^2)

# Implementation

```cpp
std::vector<int> naive_search(const std::string& h, const std::string& n) {
    std::vector<int> r;
    for (int begin = 0; begin + n.size() <= h.size(); ++begin()) {
        bool matched = true;
        for (int i = 0; i < n.size(); ++i) {
            if (h[begin + i] != n[i]) {
                matched = false;
                break;
            }
        }
        if (matched) {
            r.push_back(begin);
        }
    }
    return r;
}
```
