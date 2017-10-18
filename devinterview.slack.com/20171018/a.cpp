//https://leetcode.com/problems/decode-ways/description/

// A message containing letters from A-Z is being encoded to numbers
// using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total
// number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or
// "L" (12).

// The number of ways decoding "12" is 2.


// [12:22] 
// class Solution {
// public:
//    int numDecodings(string s) {
       
//    }
// };

#include <cstdio>
#include <string>

using namespace std;

// class Solution {
// public:
//   int _numDecodings(string s) {
//     // printf("%d %s\n", s.size(), s.c_str());
                                 
//     // base condition
//     if (s.size() == 0)
//       return 1;
//     else if (s.size() == 1)
//       return s[0] != '0' ? 1 : 0;
//     // recursion
//     // s.size() >= 2
//     if (s[0] == '0')
//       return 0;
//     int n = stoi(s.substr(0, 2));
//     if (n > 26)
//       return _numDecodings(s.substr(1));
//     return _numDecodings(s.substr(1)) + _numDecodings(s.substr(2));
//   }
//   int numDecodings(string s) {
//     if (s.empty())
//       return 0;
//     return _numDecodings(s);
//   }
// };

class Solution {
 public:
  int numDecodings(string s) {
    // base condition
    if (s.empty())
      return 0;
    if (s.size() == 1)
      return s[0] == '0' ? 0 : 1;
    if (s.size() == 2) {
      int n = stoi(s);
      if (n > 0 && n <= 26)
        return 2;
      return 0;
    }
    // iteration
    int a = 1;
    int b = 1;
    int r = 0;

    for (int i = 2; i < s.size(); ++i) {
      r = 0;
      if (s[i-1] == '0' && s[i-2] == '0') {
        return 0;
      } else if (s[i-1] > '0') {
        r = b;
      } else if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) {
        r += a;
      }
      a = b;
      b = r;
    }
    return r;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.numDecodings("1"));
  // string s = "10";
  // printf("%d %d\n", s.substr(1).size(), s.substr(2).size());
  return 0;
}
