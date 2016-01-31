// Copyright 2016 Andrew Vaziri
// CtCI Question #
// |||Prompt|||
// Implment an alogirthm  to find the kith to last element of a singly linekd
// list.
// |||Questions I might ask|||
// --How am I givent he linked list? What exactly should I return?
// --When we say Kth from last, is that zero based or one based?
// --What should I do if there are less than K-1 elements in the list? What
// should I do if someone gives me a negative value for K?
// --Can I assume the list holds ints for simplicty sake?

// |||Possible Implementations|||

#include <forward_list>
#include <iterator>
#include <iostream>
#include "../include/2.2.h"

namespace CtCI {

// |||Implementation 1|||
// Iterate through the list once to count the number of elements. Use the
// result to calculate which element to return. Assuming zero indexed. That
// would be the (N-k-1)th element after the begining.
// |||Time Complexity|||
// N = the number of elements in the list. At worst you iterate through the
// list twice, that is O(N)
// |||Space Complexity|||
// You only make one new thing; the output of the function. O(1)
std::forward_list<int>::const_iterator KthToLast(std::forward_list<int> L,
                                                 int k) {
  int N = 0;
  for (std::forward_list<int>::const_iterator it = L.begin();
       it != L.end();
       ++it) {
    N++;
  }
  if (k < 0) {
    return std::next(L.begin(), (N-1));
  }
  if ((k-1) > N) return L.begin();  // If k is too large return begining of list
  return std::next(L.begin(), (N-k-1));
}

}  // namespace CtCI
