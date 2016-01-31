// Copyright 2016 Andrew Vaziri
#ifndef _2_2_H
#define _2_2_H
#include <forward_list>
#include <string>

namespace CtCI {
std::forward_list<int>::const_iterator KthToLast(std::forward_list<int> L,
                                                 int k);
}  // namespace CtCI
#endif  // _2_2_H
