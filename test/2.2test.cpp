// Copyright Andrew Vaziri 2016
#include <iostream>
#include <forward_list>

#include "../include/2.2.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class _2_2_test : public ::testing::Test {
 protected:
  std::forward_list<int> input;
  // You can remove any or all of the following functions if its body
  // is empty.

  _2_2_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_2_2_test() {
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

TEST_F(_2_2_test, handlesZeroInput) {
  input.push_front(3);
  input.push_front(2);
  input.push_front(1);
  std::forward_list<int>::const_iterator it = CtCI::KthToLast(input, 0);
  EXPECT_EQ(*it, 3);
}

TEST_F(_2_2_test, handlesNegativeInput) {
  input.push_front(3);
  input.push_front(2);
  input.push_front(1);
  std::forward_list<int>::const_iterator it = CtCI::KthToLast(input, -10);
  EXPECT_EQ(*it, 3);
}

TEST_F(_2_2_test, handlesBeyondRangeInput) {
  input.push_front(3);
  input.push_front(2);
  input.push_front(1);
  std::forward_list<int>::const_iterator it = CtCI::KthToLast(input, 10);
  EXPECT_EQ(*it, 1);
}

TEST_F(_2_2_test, handlesNonEndOrBeginInput) {
  input.push_front(3);
  input.push_front(2);
  input.push_front(1);
  std::forward_list<int>::const_iterator it = CtCI::KthToLast(input, 1);
  EXPECT_EQ(*it, 2);
}

TEST_F(_2_2_test, handlesBeginInput) {
  input.push_front(3);
  input.push_front(2);
  input.push_front(1);
  std::forward_list<int>::const_iterator it = CtCI::KthToLast(input, 2);
  EXPECT_EQ(*it, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

