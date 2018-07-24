/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/821/

#include <cstdio>
#include <string>
#include <unordered_set>

// Rejected:
// Wrong Answer
// Input: 1 333
// Output: 0.(0)
// Expected: 0.(003)
class Solution {
 public:
  std::string fractionToDecimal(int n, int d) {
    if (n == 0)
      return "0";
    // 
    bool neg = false;
    int rep_n = -1; // repeat n
    if ((n < 0 && d > 0) ||
        (n > 0 && d < 0))
      neg = true;

    //
    double d_n = (double)n;
    double d_d = (double)d;
    double d_q = d_n / d_d;
    int64_t ll_q = (int64_t)d_q;
    d_q = d_q - ll_q;
        
    std::string s_s = neg ? "-" : "";
    std::string s_i = std::to_string(ll_q);
    std::string s_f = "";

    d_q *= 10.0;
    std::unordered_set<int> s;
   
    while (d_q > 0) {
      int i = (int)d_q;
      if (s.emplace(i).second == false) {
        rep_n = i;
        break;
      }
      d_q -= i;
      s_f += std::to_string(i);
      d_q *= 10.0;
      // printf("%d\n", i);
    }
    std::string rr = s_s + s_i;
    if (!s_f.empty()) {
      if (rep_n < 0) {
        rr += "." + s_f;
      } else {
        // insert (
        int pos = s_f.find_first_of(std::to_string(rep_n));
        s_f.insert(s_f.begin() + pos, '(');
        rr += "." + s_f + ")";
      }
    }
    return rr;
  }
};

int main() {
  // int a = 1, b = 2;
  // int a = 2, b = 1;
  // int a = 2, b = 3;
  int a = 1, b = 3;
  
  Solution s;
  printf("%s\n", s.fractionToDecimal(a, b).c_str());

  // printf("%lf\n", 1.0 / 3.0);
  
  return 0;
}
