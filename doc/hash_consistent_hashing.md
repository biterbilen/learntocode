# Abstract

- consistent hashing에 대해 적는다.

# Idea

- key, value를 저장할때 value를 여러곳들중 하나로 분산 저장하는 경우를
  생각해보자. hash(key)에 해당하는 저장소를 10개 사용하다가 9개로
  줄이거나 11개로 늘릴 수 있다. 분산저장소의 개수가 변경될떄 가능한
  value의 저장소 변경을 최소화 하여 저장하는 방법이다.

# Implementation

- []()

```cpp
int32 _t JumpConsistentHash(uint64_t key, int32_t num_buckets) { 
	int64_t b =­-1, j = 0; 
	while (j < num_buckets) { 
		b = j; 
		key = key * 2862933555777941757ULL + 1; 
		j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1)); 
	} 
	return b; 
}
#include <iostream>
#include <stdint.h>
#include <map>

using namespace std;

int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets) {
	uint64_t b =-1, j = 0;
	while (j < num_buckets) {
		b = j;
		key = key * 2862933555777941757ULL + 1;
		j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
	}
	return b;
}
int main(int argc, char **argv) {
	map<int, int> map1;
	map<int, int>::iterator mi;
	int32_t v;
	for (uint64_t i = 0; i < 100000; i++) {
		v = JumpConsistentHash(i, 8);
		mi = map1.find(v);
		if (mi == map1.end()) {
			map1[v] = 1;
		} else {
			mi->second++;
		}
	}
	for (mi=map1.begin(); mi !=map1.end(); ++mi) {
		cout << mi->first << " : " << mi->second << endl;
	}
}
```

# References

- [consisten hashing @ joinc](https://www.joinc.co.kr/w/man/12/hash/consistent)
- [A Fast, Minimal Memory, Consistent Hash Algorithm](https://arxiv.org/pdf/1406.2294.pdf)