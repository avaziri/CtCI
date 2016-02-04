// Copyright 2016 Andrew Vaziri
// CtCI Question #3.2
// |||Prompt|||
// How would you design a stack which in addition to push and pop had a
// function min which returns the minimum element? Push, pop and min all
// act in O(1) time
// |||Questions I might ask|||
// --How do I handle calls to min and pop when nothing is stored in the
// list.
// |||Possible Implementations|||
#include "../include/3.2.h"

#include <algorithm>
#include <utility>
#include <forward_list>
#include <string>
#include <sstream>

namespace CtCI {

// |||Implementation 1|||
// Use a linked list to represent the stack. Instead of storing just the values
// which are pushed, also store the current minimum at each instant.
// |||Time Complexity|||
// N = number of elements in the list. All operations are O(1) as noted in
// the prompy.
// |||Space Complexity|||
// N = number of elements in the list. We store two things for eahc node,
// O(2N) = O(N)
StackWithMin::StackWithMin() {
}

int StackWithMin::pop() {
  // If stack has no elements, allow stack.peek_front() to throw an error
  std::pair<int, int> pair = stack.front();
  stack.pop_front();
  return std::get<0>(pair);
}

void StackWithMin::push(int data) {
  std::pair<int, int> new_pair;
  if (!stack.empty()) {
    std::pair<int, int> current = stack.front();
    int minimum = std::min(data, std::get<1>(current));
    new_pair = std::make_pair(data, minimum);
  } else {
    new_pair = std::make_pair(data, data);
  }
  stack.push_front(new_pair);
  return;
}

int StackWithMin::min() {
  // If stack has no elements, allow stack.peek_front() to throw an error
  std::pair<int, int> current = stack.front();
  int out = std::get<1>(current);
  return out;
}

// Helper Function
std::string StackWithMin::ToString() {
  std::stringstream ss;
  ss << "[";
  for (auto it = stack.begin(); it != stack.end(); ++it) {
    if (it == stack.begin()) {
      ss << std::get<0>(*it);
    } else {
      ss << ", " << std::get<0>(*it);
    }
  }
  ss << "]";
  return ss.str();
}



}  // namespace CtCI
