// Copyright 2016 Andrew Vaziri
#ifndef _2_2_H
#define _2_2_H
#include <forward_list>
#include <string>

namespace CtCI {
std::forward_list<int>::const_iterator KthToLast1(std::forward_list<int> L,
                                                 int k);
std::forward_list<int>::const_iterator KthToLast2(std::forward_list<int> L,
                                                 int k);
std::forward_list<int>::const_iterator RecursiveHelper2(
  const std::forward_list<int>& L,
  std::forward_list<int>::const_iterator it,
  int* counter,
  int k);
}  // namespace CtCI
#endif  // _2_2_H
