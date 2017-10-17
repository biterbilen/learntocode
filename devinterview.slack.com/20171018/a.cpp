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

class Solution {
public:
  int _numDecodings(string s) {
    // base condition
    if (s.size() == 0)
      return 1;
    else if (s.size() == 1)
      return stoi(s) > 0 ? 1 : 0;
    // recursion
    // s.size() >= 2
    int n = stoi(s.substr(0, 2));
    if (n > 26)
      return numDecodings(s.substr(1));
    return numDecodings(s.substr(1)) +
        numDecodings(s.substr(2));
  }
  int numDecodings(string s) {
    if (s.empty())
      return 0;
    return _numDecodings(s);
  }
};

int main() {
  Solution s;
  printf("%d\n", s.numDecodings("10"));  
  return 0;
}
