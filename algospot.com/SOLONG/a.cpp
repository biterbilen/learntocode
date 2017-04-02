// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/SOLONG

#include <cstdio>
#include <vector>
#include <map>
#include <string>

int N, M;
std::vector<std::pair<int, int>> DICT;
std::vector<std::string> DICTWORDS;
std::vector<int> PRIORITIES;
std::vector<std::string> WORDS;

void print_v_string(const std::vector<std::string>& v) {
  for (auto x : v)
    printf("%s ", x.c_str());
  printf("\n");
}

class TrieNode {
};

int solve() {
  
  
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    DICT.clear(); DICT.resize(N);
    DICTWORDS.clear(); DICTWORDS.resize(N);
    PRIORITIES.clear(); PRIORITIES.resize(N);
    WORDS.clear(); WORDS.resize(M);
    for (int i = 0; i < N; ++i) {
      char buf[16];
      int priority;
      scanf("%s %d", buf, &priority);
      DICTWORDS[i] = buf;
      PRIORITIES[i] = priority;
      DICT[i] = std::make_pair(i, priority);
    }
    for (int i = 0; i < M; ++i) {
      char buf[16];
      scanf("%s", buf);
      WORDS[i] = buf;
    }
    print_v_string(WORDS);
    // printf("%d\n", solve());
  }
  return 0;
}
