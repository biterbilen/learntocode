// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/2/A
#include <string>
#include <map>

#define MININT -987654321

int N;

int main() {
  scanf("%d", &N);
  std::string best_name;
  int best_score = MININT;
  std::map<std::string, int> m;
  for (int i = 0; i < N; ++i) {
    char buf[64];
    int score;
    scanf("%s %d", buf, &score);
    auto it = m.find(buf);
    if (it == m.end()) {
      m[buf] = 0;
    }
    m[buf] += score;
    if (best_score < m[buf]) {
      best_name = buf;
      best_score = m[buf];
    }
  }
  printf("%s\n", best_name.c_str());

  return 0;
}
