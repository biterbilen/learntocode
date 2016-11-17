// Copyright (C) 2016 by iamslash

// Palindrome Permutation: Given a string, write a function to
// check if it is a permutation of a palindrome. A palindrome is a
// word or phrase that is the same forwards and backwards. A
// permutation is a rearrangement of letters.The palindrome does not
// need to be limited to just dictionary words.

// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat". "atco cta". etc.)

// CORNERCASE
//

#include <string>
#include <algorithm>

bool IsPermutation(const std::string& _s0, const std::string& _s1) {

  std::string s0(_s0);
  std::string s1(_s1);
  std::sort(s0.begin(), s0.end());
  std::sort(s1.begin(), s1.end());

  for (auto it = s1.begin(); it != s1.end(); ++it) {
    if (s0.find(*it) == std::string::npos)
      return false;
  }
  
  return true;
}

std::vector<std::string> GetPalindromePermutation(const std::string& s) {
  std::vector<std::string> r;
  
  return r;
}

int main() {
  std::string s = "Tact Coa";
  std::vector<std::string> pp = GetPalindromePermutation(s);
  printf("%s", pp.size() > 0 ? "True" : "False");

  return 0;
}
