// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NERDS2

#include <string>
#include <algorithm>
#include <iostream>
#include <map>

int N;

void print_m_int_int(const std::map<int, int>& m) {
  for (auto it = m.cbegin(); it != m.cend(); ++it) {
    printf("[%4d : %4d] ", it->first, it->second);
  }
  printf("\n");
}

bool is_dominated(const std::map<int, int>& m, int x, int y) {
  
  return true;
}

void del_dominated(const std::map<int, int>& m, int x, int y) {
}

int reg_cand(std::map<int, int>& m, int x, int y) {
  // 새로운 참가자는 기존의 참가자들에게 점유되는가???
  if (is_dominated(m, x, y))
    return m.size();
  // 새로운 참가자에게 점유되는 기존의 참가자들을 제거하자.
  del_dominated(m, x, y);
  // 새로운 참가자는 추가되야 한다.
  m[x] = y;
  return m.size();
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);

    std::map<int, int> m;
    int x, y, r = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d %d", &x, &y);
      r += reg_cand(m, x, y);
    }
    printf("%d\n", r);
  }
  //
  return 0;
}
