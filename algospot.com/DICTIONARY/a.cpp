// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/DICTIONARY

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

void print_v_int(const std::vector<int>& v) {
  if (v.size() == 0) {
    printf("INVALID HYPOTHESIS");
  } else {
    for (int i = 0; i < v.size(); ++i) {
      printf("%c", v[i]+'a');
    }
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    std::vector<std::string> words;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      char buf[128];
      scanf("%s", buf);
      words.push_back(buf);
    }

    MakeGraph(words);
    std::vector<int> r = TopologicalSort();

    PrintVInt(r);
  }
  //
  return 0;
}
