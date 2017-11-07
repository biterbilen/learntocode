// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/minimum-window-substring/description/
// http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

// Given a string S and a string T, find the minimum window in S witch
// will contain all the characters in T in complexity O(n).

// For example,
// S = “ADOBECODEBANC”
// T = “ABC”
// minimum window is “BANC”

// S = “bba”
// T = “ab”
// minimum window is “ba”

// If there is no such window in S that covers all characters in T,
// return the empty string “”;

// if there are multiple such windows, you are guaranteed that there
// will always be only one unique minimum window in S.

//  t  f
// “ADOBECODEBANC”
// "ABC"

const int MAX_INT = 9876543210;

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    int matched_cnt = 0;
    int s_cnt[256] = {0,};
    int t_cnt[256] = {0,};
    int fr_idx_min = MAX_INT;
    int len_min = MAX_INT;
    int fr_idx = 0;

    // validate s
    if (s.size() < t.size())
      return "";

    // set t_cnt
    for (int i = 0; i < t.size(); ++i) {
      t_cnt[t[i]]++;
      s_cnt[s[i]]++;
    }

    // traverse s to make a min window
    for (int to_idx = t.size(); to_idx < s.size(); ++to_idx) {
      // move right idx of window
      s_cnt[s[to_idx]]++;
      
      // move left idx of window
      if (matched_cnt == t.size()) {

      }

      // set len_min
      if (len_min > (to_idx - fr_idx + 1)) {
        fr_idx_min = fr_idx;
        len_min = to_dix - fr_idx + 1;
      }
      
    }

    return s.substr(fr_idx_min, len_min);
  }
};

int main() {
  S s;
  printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
}
