// Copyright 2016 Andrew Vaziri
// CtCI Question #1.2
// |||Prompt|||
// Given two strings, write a method to decide if one is a permutation of the
// other
// |||Questions I might ask|||
// Are we using unicode or ascii?
// This method is case sensitive?
// I am given a string and return true or false


// |||Possible Implementations|||
#include "../include/1.1.h"
#include <string>
#include <unordered_map>

namespace CtCI {

// |||Implementation 1|||
// Create a hash map for the string 1, increment the value in the map for each
// occourance of a character. Then decrement the value for each occourance of
// that same character in the next string. If all values are zero they are
  // permutations of each other, otherwise they are not.
// |||Time Complexity|||
// N = # characters in string 1, M = # characters in string 2, O(M+N) a
// a constant number of operations are done for each character in each string
// |||Space Complexity|||
// O(N+M), there are a constant number of stored values, N in one string, M in
// the other, and at most N+M in the hash map

bool IsPermutation(const std::string& str1, const std::string& str2) {
  std::unordered_map<char, int> count;
  for (std::string::const_iterator it1 = str1.begin();
       it1 != str1.end();
       ++it1) {
    auto cur = count.insert({*it1, 0});  // Returns iterator pointing to element
                                  //  with that key value
    (cur.first->second)++;
  }
  for (std::string::const_iterator it2 = str2.begin();
       it2 != str2.end();
       ++it2) {
    auto cur = count.insert({*it2, 0});  // Returns iterator pointing to element
                                  // with that key value
    (cur.first->second)--;
  }
  for (std::unordered_map<char, int>::const_iterator  it = count.begin();
       it != count.end();
       ++it) {
    if ( it->second != 0) return false;
  }
  return true;
}
}  // namespace CtCI
