// Copyright Andrew Vaziri 2016
#include <string>
#include "../include/1.2.h"
#include "gtest/gtest.h"


// The fixture for testing class Foo.
class _1_2_test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  _1_2_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_1_2_test() {
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

TEST_F(_1_2_test, noOverlap) {
  const std::string& test1 = "yo";
  const std::string& test2 = "hi";
  EXPECT_EQ(CtCI::IsPermutation(test1, test2), false);
}
TEST_F(_1_2_test, someOverlap) {
  const std::string& test1 = "yo";
  const std::string& test2 = "hello";
  EXPECT_EQ(CtCI::IsPermutation(test1, test2), false);
}
TEST_F(_1_2_test, uniqueCharsPermutation) {
  const std::string& test1 = "abc";
  const std::string& test2 = "cab";
  EXPECT_EQ(CtCI::IsPermutation(test1, test2), true);
}
TEST_F(_1_2_test, nonUniqueCharsPermutation) {
  const std::string& test1 = "aabbccdd";
  const std::string& test2 = "abcdabcd";
  EXPECT_EQ(CtCI::IsPermutation(test1, test2), true);
}
TEST_F(_1_2_test, emptyString) {
  const std::string& test1 = "";
  const std::string& test2 = "";
  EXPECT_EQ(CtCI::IsPermutation(test1, test2), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

