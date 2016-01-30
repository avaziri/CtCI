// Copyright 2016 Andrew Vaziri
// CtCI Question 2.1
// |||Prompt|||
// Write code to remove duplicates from an unsorted linked list.
// |||Questions I might ask|||
// --Do I have to keep the elements that are not removed in the same order?
// --Can I say that the list holds integers whiteboard simplicity sake?
// --Am I given the list by reference or by value? Do I return a list or a
// pointer to a list?
// --Must I modify the list I am given in place?
// --Should I account for improper inputs (e.g. null list pointer or something
// that is not a list)
// |||Possible Implementations|||

#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <unordered_map>
#include "../include/2.1.h"

namespace CtCI {

// |||Implementation 1|||
// Create a new list. Each time you find a previously unseen
// value, add it to the list. The list is also used for checking what has been
// seen in the past. Checking for uniqueness in this way is not optimal, there
// are better data strucutres (hash table).
// |||Time Complexity|||
// N = # of elements in the list. The worst case is that all the elements are
// unique. This results in N iterations through the list, during each the
// check for uniqueness grows more costly (1,2,3,...,N). Such a series averages
// to N/2. In total that:  O(N) * O(N/2) = O(N^2)
// |||Space Complexity|||
// N = # of elements in the list. The worst case is that all the elements are
// unique. This would result in O(N)
std::list<int> RemoveDups1(std::list<int> L) {
  std::list<int> out;
  for (std::list<int>::const_iterator it = L.begin();
       it != L.end();
       ++it) {
    bool seen = 0;
    for (std::list<int>::const_iterator it_o = out.begin();
         it_o != out.end();
         ++it_o) {
      if (*it == *it_o) {
        seen = 1;
        break;
      }
    }
    if (seen == 0) {
      int unique_val = *it;
      out.push_front(unique_val);
    }
  }
  return out;
}

// |||Implementation 2|||
// Iterate through the list. Check the hash table to see if that value has been
// seen before. If it has then erase the corresponding node. If it has not been
// update the hash table and continue to the next element of the list.
// |||Time Complexity|||
// N = # of elements in the list. The algorithm must iterate over N elements,
// but checking and updating the hash table is constant time. So the algorithm
// will be O(N).
// |||Space Complexity|||
// N = # of elements in the list. The list itself takes N elements worth of
// space the hash table takes O(N) space. In total still O(N) space complexity.
std::list<int> RemoveDups2(std::list<int> L) {
  std::unordered_map<int, bool> hash_table;
  int seen;
  for (std::list<int>::iterator it = L.begin(); it != L.end(); ++it) {
    try {
      seen = hash_table.at(*it);  // throws if key is not mapped to a value
    } catch (std::out_of_range ex) {
      seen = 0;
      hash_table.insert({*it, 1});
    }
    if (seen == 1) {
      it = L.erase(it);
      // it--;  // I thought this line should be necessary, but all the tests
               // pass with or without it....???
    }
  }
  return L;
}

// Helper Function
std::string ListToString(std::list<int> L) {
  std::stringstream ss;
  ss << "[";
  for (std::list<int>::const_iterator it = L.begin(); it != L.end(); ++it) {
    if (it == L.begin()) {
      ss << *it;
    } else {
      ss << ", " << *it;
    }
  }
  ss << "]";
  return ss.str();
}

}  // namespace CtCI
