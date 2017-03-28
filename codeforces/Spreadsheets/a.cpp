// Copyright (C) 2017 by iamslash
#include <cstdio>
#include <cstdint>
#include <string>
#include <regex>

int main() {
  std::regex pattern("[A-Z]+[0-9]+");
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    char buf[128];
    scanf("%s", buf);
    std::string s = buf;
    if (std::regex_match(s, pattern)) {
      printf("1");
    } else {
      printf("2");
    }
    printf("\n");
  }

  return 0;
}
