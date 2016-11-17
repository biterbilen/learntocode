// Copyright (C) 2016 by iamslash

// String Compression: Implement a method to perform basic string
// compression using the counts of repeated characters. For example,
// the string aabcccccaaa would become a2blc5a3. If the
// "compressed"string would not become smaller than the original
// string, your method should return the original string. You can
// assume the string has only uppercase and lowercase letters (a - z).

// CORNERCASE
// 0. max compressed cnt ?

#include <string>
#include <cstdlib>

std::string StringCompress(const std::string& s) {
  std::string r;
  int j = 0;
  char b = '\0';
  for (int i = 0; i < s.size(); ++i) {
    printf("%d %d %c\n", i, j, b);
    if (b != s[i]) {
      if (j != 0) {
        char buf[256] = {0, };
        itoa(j, buf, 10);
        r += b;
        r += buf;
      }
      j = 1;
      b = s[i];
    } else {
      ++j;
    }
  }

  return r;
}

int main() {
  std::string s0 = "aabcccccaaa";
  printf("%s\n", StringCompress(s0).c_str());

  return 0;
}
