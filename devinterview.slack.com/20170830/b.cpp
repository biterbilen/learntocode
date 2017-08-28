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
