// Copyright (C) 2017 by iamslash

// Given a dictionary, and two words ‘start’ and ‘target’ (both of
// same length). Find length of the smallest chain from ‘start’ to
// ‘target’ if it exists, such that adjacent words in the chain only
// differ by one character and each word in the chain is a valid word
// i.e., it exists in the dictionary. It may be assumed that the
// ‘target’ word exists in dictionary and length of all dictionary
// words is same.

// Example:

// Input:  Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}
//             start = TOON
//             target = PLEA
// Output: 7
// Explanation: TOON - POON - POIN - POIE - PLIE - PLEE - PLEA

// g++ b.cpp -std=c++11 -o b.exe

#include <cstdio>
#include <vector>
#include <set>
#include <string>

// Exhaustive search
// O(N!)
// ???
int MAX = 987654321;
int BEST = MAX;
bool is_adj(const std::string& a, const std::string&b) {
  if (a.size() != b.size())
    return false;
  int n = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      ++n;
      if (n > 1)
        break;
    }
  }
  if (n == 1)
    return true;
  return false;
}

void _solve(std::set<std::string>& s, const std::string& prev, const std::string& end, int n_lv) {
  // base condition
  if (s.empty()) {
    BEST = n_lv;
    return;
  }
  // pruning
  if (BEST <= n_lv)
    return;
  // recursion
  for (const auto& e : s) {
    if (is_adj(e, prev)) {
      s.remove(e);
      _solve(s, e, end, n_lv + 1);
      s.insert(e);
    }
  }
}

int solve(const std::vector<std::string>& v, std::string start, std::string target) {
  std::set<std::string> s;
  for (const auto& e : v)
    s.insert(e);
  for (const auto& e : s) {
    _solve(s, e, target, 0);
  }
  return BEST;
}

int main() {
  int r = solve({"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"}, "TOON", "PLEA");
  if (r == 0 || r == MAX) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", r);
  }
  return 0;
}
