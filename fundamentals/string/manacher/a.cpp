// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <string>

std::string solve(std::string h) {
  std::string s(2 * h.size() + 1, '.');
  std::vector<int> z(s.size());
  for (int i = 0; i < s.size(); ++i)
    s[2 * i + 1] = h[i];
  for (int j, r = 0, i = 0; i < s.size(); ++i) {
    if (i < r && z[2 * j - i] != r - i) {
      z[i] = std::min(z[2 * j - i], r - i);
    } else {
      j = i;
      r = std::max(r, i);
      while (r < s.size() && (2 * j - r) >= 0 &&
             s[j] == s[2 * j - r])
        r++;
      z[i] = r - j;
    }
  }
  int x = std::max_element(z.begin(), z.end()) - z.begin();
  return h.substr((x - z[x] + 1) / 2, z[x] - 1);
}

int main() {
  printf("%s\n", solve("banana").c_str());
  return 0;
}
