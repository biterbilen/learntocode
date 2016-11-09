// Copyright (C) 2016 by iamslash
// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    string reverseString(string s) {
        string r(s);
        reverse(r.begin(), r.end());
        return r;
    }
};
