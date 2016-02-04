// Copyright Andrew Vaziri 2016
#include <iostream>
#include <forward_list>
#include <string>
#include <sstream>

#include "../include/3.2.h"
#include "gtest/gtest.h"


// The fixture for testing class Foo.
class _3_2_test : public ::testing::Test {
 protected:
  CtCI::StackWithMin* stack;
  // You can remove any or all of the following functions if its body
  // is empty.

  _3_2_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_3_2_test() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    stack = new CtCI::StackWithMin();
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(_3_2_test, printEmptyWorks) {
  EXPECT_EQ(stack->ToString(), "[]");
}

TEST_F(_3_2_test, pushWorks) {
  stack->push(100);
  stack->push(50);
  stack->push(25);
  EXPECT_EQ(stack->ToString(), "[25, 50, 100]");
}

TEST_F(_3_2_test, minHandlesMostRecent) {
  stack->push(100);
  stack->push(50);
  stack->push(25);
  int min = stack->min();
  EXPECT_EQ(min, 25);
}

TEST_F(_3_2_test, minHandlesMidRecent) {
  stack->push(100);
  stack->push(25);
  stack->push(50);
  int min = stack->min();
  EXPECT_EQ(min, 25);
}

TEST_F(_3_2_test, minHandlesLeastRecent) {
  stack->push(25);
  stack->push(100);
  stack->push(50);
  int min = stack->min();
  EXPECT_EQ(min, 25);
}

TEST_F(_3_2_test, popWorks) {
  stack->push(20);
  int val = stack->pop();
  EXPECT_EQ(val, 20);
}

TEST_F(_3_2_test, minHandlesPopThenMin) {
  stack->push(20);
  stack->push(19);
  stack->push(18);
  stack->pop();
  int min = stack->min();
  EXPECT_EQ(min, 19);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

