// Copyright (C) 2016 by iamslash
// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
        }
        return s;
    }
};
