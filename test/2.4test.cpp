// Copyright Andrew Vaziri 2016
#include <iostream>
#include <forward_list>
#include <string>
#include <sstream>

#include "../include/2.4.h"
#include "gtest/gtest.h"

// Helper Function
std::string FwdListToString(std::forward_list<int> L) {
  std::stringstream ss;
  ss << "[";
  for (auto it = L.begin(); it != L.end(); ++it) {
    if (it == L.begin()) {
      ss << *it;
    } else {
      ss << ", " << *it;
    }
  }
  ss << "]";
  return ss.str();
}

// The fixture for testing class Foo.
class _2_4_test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  _2_4_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_2_4_test() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(_2_4_test, 1test1) {
  std::forward_list<int> input1{1, 5, 6, -2, 0, 4, 10, 3, 4, 4, 7};
  CtCI::Partition1(&input1, 5);
  EXPECT_EQ(FwdListToString(input1), "[4, 4, 3, 4, 0, -2, 1, 5, 6, 10, 7]");
}

TEST_F(_2_4_test, 1handles_empty_list) {
  std::forward_list<int> input1;
  CtCI::Partition1(&input1, 5);
  EXPECT_EQ(FwdListToString(input1), "[]");
}

TEST_F(_2_4_test, 1handles_move_all_elements) {
  std::forward_list<int> input1{1, 5, 6, -2, 0, 4, 10, 3, 4, 4, 7};
  CtCI::Partition1(&input1, 999);
  EXPECT_EQ(FwdListToString(input1), "[7, 4, 4, 3, 10, 4, 0, -2, 6, 5, 1]");
}

TEST_F(_2_4_test, 1handles_move_no_elements) {
  std::forward_list<int> input1{1, 5, 6, -2, 0, 4, 10, 3, 4, 4, 7};
  CtCI::Partition1(&input1, -999);
  EXPECT_EQ(FwdListToString(input1), "[1, 5, 6, -2, 0, 4, 10, 3, 4, 4, 7]");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

