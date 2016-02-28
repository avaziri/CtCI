// Copyright 2016 Andrew Vaziri
// CtCI Question #1.1
// |||Prompt|||
// Implement an algorithm to detrime if a string has all unique characters.
// What if you cannot use additional data structures?
// |||Questions I might ask|||
// --So I get a string by reference as an input and I output a bool isUnique?
// --Do you want to see good fundamentals (hashing) or should I make use of the
// fact that they are characters to remove even the overhead of setting up a
// hash set.
// Do lowercase and upercase letters count as different characters?

// |||Possible Implementations|||
#include "../include/1.1.h"
#include <algorithm>
#include <string>
#include <unordered_set>

namespace CtCI {

// |||Implementation 1|||
// Take advantage of the fact that there are a limited set of characters that
// can be present in the string. Initialize a vector of bools equal with length
// = # of possible characters. Subtract an offset from the ASCII values of the
// characters to get direct access to the desired number in the vector. If it
// is 0 set it to 1, if it is 1 return isUnique = 0. If you get through
// proccesing the whole string return isUnique = 1 ;
// |||Time Complexity|||
// N = number of characters in the string. This  algorithm would be O(N), this
// method performs a constant time lookup for each of the N characters in the
// string.
// |||Space Complexity|||
// The space required for this implementation is O(1), it does not depend on
// the number of characters in the string. But practically, the ammount of space
// will be suboptimal when compared to methods that only store characters as
// they occour.

// I am not actually going to write implmentation 1

// |||Implementation 2|||
// For each character check if it is in the hash set. If it is then return
// isUnique = flase. Otherwise add the character to the hash set and continue.
// If the end of the string is reached return isUnique = 1;
// |||Time Complexity|||
// N = number of characters in the string. This  algorithm would be O(N), this
// method performs a constant time lookup for each of the N characters in the
// string.
// |||Space Complexity|||
// The space required for this implementation is O(N), As new unique characters
// are found they are added to the list.

bool StringIsUnique1(const std::string& str) {
  std::unordered_set<char> seen;
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (seen.find(*it) == seen.end()) {
      seen.insert(*it);
    } else {
      return false;
    }
  }
  return true;
}

// |||Implementation 3|||
// If you cant use a data structure other than a string there is a different
// approach. First sort the string, then run through the string checking that
// the previous and current element are different.
// |||Time Complexity|||
// N = number of characters in the string. This  algorithm would be O(N) to
// iterate through the string + O(Nlog(N)) is sorting was done with quick sort.
// |||Space Complexity|||
// The space required for this implementation is O(N), for the string itself.

bool StringIsUnique2(const std::string& str) {
  if (str.length() < 2) return true;
  std::string str_mutable = str;
  std::sort(str_mutable.begin(), str_mutable.end());
  char prev = *str_mutable.begin();
  for (std::string::const_iterator it = (str_mutable.begin()+1);
       it != str_mutable.end();
       ++it) {
    if (prev == *it) return false;
    prev = *it;
  }
  return true;
}
}  // namespace CtCI
