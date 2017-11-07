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

//  t
// “ADOBECODEBANC”
// "ABC"
class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    int matched_cnt = 0;
    int s_cnt[256] = {0,};
    int t_cnt[256] = {0,};
    int fr_idx_min = 0;
    int len_min = s.size();

    // validate s
    if (s.size() < t.size())
      return "";

    // set t_cnt
    for (int i = 0; i < t.size(); ++i) {
      t_cnt[i]++;
    }

    // traverse s to make a minim window
    for (int to_idx_min = 0; to_idx_min < s.size(); ++to_idx_min) {
      
    }

    return s.substr(fr_idx_min, len_min);
  }
};

int main() {
  S s;
  printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
}
