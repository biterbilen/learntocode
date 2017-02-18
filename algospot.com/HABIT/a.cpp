// Copyright (C) 2017 by iamslash

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

int K;

std::vector<int> GetSuffixArray(const std::string& s) {
  std::vector<int> r(s.size());
  for (int i = 0; i < s.size(); ++i) {
    r[i] = i;
  }
  // std::sort(r.begin(), r.end(), Comp(s));
  std::sort(r.begin(), r.end(),
            [s](int i, int j) -> bool {
              return strcmp(s.c_str()+i, s.c_str()+j) < 0;
            });
  return r;
}

int GetLcpCnt(const std::string& s, const std::vector<int>& sa, int i) {
  int r = 0;
  int j = i + K - 1;

  while (i < s.size() && j < s.size() && s[i] == s[j]) {
    r++;
    i++;
    j++;
  }

  return r;
}

int Solve(std::string s) {
  int r = 0;

  std::vector<int> sa = GetSuffixArray(s);

  for (int i = 0; i + K < sa.size(); ++i) {
    r = std::max(r, GetLcpCnt(s, sa, i));
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &K);
    char buf[4000];
    scanf("%s", buf);

    printf("%d\n", Solve(buf));
  }
}
