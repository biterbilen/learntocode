// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/1/B

#include <cstdio>
#include <cstdint>
#include <string>
#include <regex>

int get_num(const std::string& s) {
  int r = 0;
  int div = 1;
  for (int i = 0; i < s.size(); ++i, div *= 26) {
    int n = atoi(&s[i]);
    r += (n * div);
  }
  return r;
}

char get_cap_chr(int n) {
  return 'A' + n;
}

std::string get_str(int n) {
  std::string r = "";
  int div = n;
  int mod;
  do {
    n = div;
    div = n / 26;
    mod = n % 26;   
    // printf("  %d\n", div);
    if (div == 0) {
      r.insert(0, 1, get_cap_chr(mod));
    } else {
      r.insert(0, 1, get_cap_chr(div));
    }
    // printf("%s\n", r);
  } while (div > 0);
  return r;
}

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
  // std::regex re0("[A-Z]+[0-9]+");
  // std::regex renum("[0-9]+");
  // std::regex restr("[A-Z]+");
  // int N;
  // scanf("%d", &N);
  // for (int i = 0; i < N; ++i) {
  //   char buf[128];
  //   scanf("%s", buf);
  //   std::string msg = buf;

  //   std::smatch mresult;
  //   std::string row;
  //   std::string col;

  //   if (std::regex_match(msg, re0)) {
  //     std::regex_search(msg, mresult, restr);
  //     row = mresult[0];
  //     std::regex_search(msg, mresult, renum);
  //     col = mresult[0];
  //   } else {
  //     while (std::regex_search(msg, mresult, renum)) {
  //       if (row.size() == 0)
  //         row = mresult[0];
  //       else
  //         col = mresult[0];
  //       msg = mresult.suffix().str();
  //     }
  //   }
  //   // printf("%s %s\n", row.c_str(), col.c_str());
  // }

  // for (int i = 0; i < 26; ++i)
  //   printf("%c ", get_cap_chr(i));
  // printf("\n");
  printf("%s\n", get_str(54));
  // printf("%d\n", get_num("A"));
  
  return 0;
}
