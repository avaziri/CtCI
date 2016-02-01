// Copyright 2016 Andrew Vaziri
// CtCI Question # 2.4
// |||Prompt|||
// Write code to partition a linked list around a value x such that all nodes
// less than x come before all nodes greater than or equal to x. If x is
// contained within the list, the values of x only need to be after the
// elements less than x. The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right
// partitions.
// |||Questions I might ask|||
// --What do I return? A: void
// --What should we do if the list is empty? A: nothing
// --Am I passed the list by reference? A: yes

// |||Possible Implementations|||

#include <forward_list>
#include "../include/2.4.h"

namespace CtCI {

// |||Implementation 1|||
// Use the functions built into the container to complete the exercise.
// Particularly push_front and erase_after. Both operations are O(1) because 
// we have iterators directly to the node to be created or deleted. We repeat
// these operations in the worst case for all N entries.
// nodes.
// |||Time Complexity|||
// N = # of nodes in the list. In total the above is O(N)*(O(1) + O(1)) = O(N)
// |||Space Complexity|||
// The space required is the list itself which is O(N)

void Partition1(std::forward_list<int>* L, int cutoff) {
  std::forward_list<int>::iterator prev;
  for (auto it = L->begin(); it != L->end(); /*don't increment*/) {
    // If the value is less than the cutoff move it to the front
    if (*it < cutoff) {
      // If the element is already at the front
      if (it == L->begin()) {
        prev = it;  // record prev to aid in deletion next iteration
        ++it;
      } else {
        L->push_front(*it);
        it = L->erase_after(prev);
      }
    } else {  // If the value is >= the cutoff leave it where it is
      prev = it;  // record prev to aid in deletion next iteration
      ++it;
    }
  }
}

}  // namespace CtCI
