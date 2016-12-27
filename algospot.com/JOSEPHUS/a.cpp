// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/JOSEPHUS

#include <cstdio>
#include <vector>

int N, K;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

std::vector<int> Solve() {
  std::vector<int> r;

  // init v
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i;
  }

  v.erase(v.begin());
  //
  int idx = 0;
  while (v.size() > 2) {
    idx += K - 1;
    if (idx >= v.size()) {
      idx = idx % v.size();
    }

    v.erase(v.begin() + idx);
    // PrintVInt(v);
  }

  if (v[0] > v[1]) {
    r.push_back(v[1]);
    r.push_back(v[0]);
  } else {
    r.push_back(v[0]);
    r.push_back(v[1]);
  }
  
  return r;  
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &K);    
    std::vector<int> r = Solve();
    printf("%d %d\n", r[0]+1, r[1]+1);
    // printf("%d %d\n", r[0], r[1]);
  }
  
  return 0;
}

