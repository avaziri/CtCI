// Copyright Andrew Vaziri 2016
#ifndef INCLUDE_3_2_H_
#define INCLUDE_3_2_H_

#include <forward_list>
#include <utility>
#include <string>

namespace CtCI {

class StackWithMin {
 public:
  int pop();
  void push(int data);
  int min();
  StackWithMin();
  std::string ToString();
 private:
  std::forward_list<std::pair<int, int> > stack;
};

}  // namespace CtCI
#endif  // INCLUDE_3_2_H_
