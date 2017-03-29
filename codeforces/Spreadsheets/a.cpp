// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/1/B

#include <cstdio>
#include <cstdint>
#include <string>
#include <regex>

std::string get_numeration_1(const std::string row,
                             const std::string col) {
  std::string r;
  // R23C234
  return r;
}

std::string get_numeration_2(const std::string row,
                             const std::string col) {

  std::string r;
  // B33
  return r;
}

int main() {
  std::regex re0("[A-Z]+[0-9]+");
  std::regex renum("[0-9]+");
  std::regex restr("[A-Z]+");
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    char buf[128];
    scanf("%s", buf);
    std::string msg = buf;

    std::smatch mresult;
    std::string row;
    std::string col;

    if (std::regex_match(msg, re0)) {
      std::regex_search(msg, mresult, restr);
      row = mresult[0];
      std::regex_search(msg, mresult, renum);
      col = mresult[0];
    } else {
      while (std::regex_search(msg, mresult, renum)) {
        if (row.size() == 0)
          row = mresult[0];
        else
          col = mresult[0];
        msg = mresult.suffix().str();
      }
    }
    // printf("%s %s\n", row.c_str(), col.c_str());
  }

  return 0;
}
