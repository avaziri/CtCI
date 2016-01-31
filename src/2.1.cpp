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
#include <iterator>
#include <list>
#include <unordered_set>
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
// Iterate through the list. Check the hash set to see if that value has been
// seen before. If it has then erase the corresponding node. If it has not been
// update the hash set and continue to the next element of the list.
// |||Time Complexity|||
// N = # of elements in the list. The algorithm must iterate over N elements,
// but checking and updating the hash set is constant time. So the algorithm
// will be O(N).
// |||Space Complexity|||
// N = # of elements in the list. The list itself takes N elements worth of
// space the hash set takes O(N) space. In total still O(N) space complexity.
std::list<int> RemoveDups2(std::list<int> L) {
  std::unordered_set<int> hash_set;
  for (std::list<int>::iterator it = L.begin(); it != L.end(); /*no ++it*/) {
    int seen = hash_set.count(*it);
    if (seen == 0) {
      hash_set.insert(*it);
      ++it;
    } else {
      it = L.erase(it);
    }
  }
  return L;
}

// |||Implementation 3|||
// This solution addresses the follow up question of how to do this in place.
// There are two nested loops. The first loop iterates through each element in
// the list. During each iteration the second loop removes all duplicate values
// from the rest of the list.
// |||Time Complexity|||
// N = # of elements in the list. All cases take an equal amount of time. The
// outer loop completes N interations each of which requires a decreasing
// number of elements to be accesed in the inner loop (N-1, ... 1, 0). This
// represents N/2 on average. The overall complexity is O(N^2)
// |||Space Complexity|||
// N = # of elements in the list. The list itself takes N elements worth of
// space so the space complexity is O(N).
std::list<int> RemoveDups3(std::list<int> L) {
  for (std::list<int>::iterator it_o = L.begin(); it_o != L.end(); ++it_o) {
    std::list<int>::iterator it_i;
    for (it_i = std::next(it_o, 1); it_i != L.end(); /*no increment*/) {
      if (*it_o == *it_i) {
        it_i = L.erase(it_i);
      } else {
        ++it_i;
      }
    }
  }
  return L;
}

}  // namespace CtCI
