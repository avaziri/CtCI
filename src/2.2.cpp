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
std::forward_list<int>::const_iterator KthToLast1(std::forward_list<int> L,
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

// |||Implementation 1|||
// Call a function recursively until it reaches the final elemnent. From that
// point incrment the value the is passed up. When the count has reached the
// Kth from the end return an iterator to that 
// |||Time Complexity|||
// N = the number of elements in the list. The worst case is that it has to go
// all the way down through the nodes then back up the stack. This is O(N) +
// O(N) = O(N)
// |||Space Complexity|||
// This method makes O(N) frames on the stack.
std::forward_list<int>::const_iterator KthToLast2(std::forward_list<int> L,
                                                 int k) {
  int* counter = new int(0);
  std::forward_list<int>::const_iterator it = RecursiveHelper2(
    L,
    L.cbegin(),
    counter,
    k);
  delete counter;
  return it;
}

std::forward_list<int>::const_iterator RecursiveHelper2(
  const std::forward_list<int>& L,
  std::forward_list<int>::const_iterator it,
  int* counter,
  int k) {
  if (std::next(it) != L.cend()) {
    std::forward_list<int>::const_iterator it_out = RecursiveHelper2(
      L,
      std::next(it),
      counter,
      k);
    // The default case is to return the last element, I decided that if K is
    // too large then the first node should be returned which necessitates
    // the following check
    if (it == L.cbegin() && k > *counter) {
      return it;
    }
    // If the current node is Kth from the end start passing that up the stack
    if (*counter == k) {
      (*counter)++;
      return it;
    // Otherwise pass the previous result up the stack
    } else {
      (*counter)++;
      return it_out;
    }
    // If this is the last element pass it up the stack
  } else {
    (*counter)++;
    return it;
  }
}
}  // namespace CtCI
