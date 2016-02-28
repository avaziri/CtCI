// Copyright Andrew Vaziri 2016
#include <string>
#include "../include/1.1.h"
#include "gtest/gtest.h"


// The fixture for testing class Foo.
class _1_1_test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  _1_1_test() {
    // You can do set-up work for each test here.
  }

  virtual ~_1_1_test() {
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

TEST_F(_1_1_test, 1nonRepeating) {
  const std::string& test = "hey";
  EXPECT_EQ(CtCI::StringIsUnique1(test), true);
}
TEST_F(_1_1_test, 1nullString) {
  const std::string& test = "";
  EXPECT_EQ(CtCI::StringIsUnique1(test), true);
}
TEST_F(_1_1_test, 1repeatingString) {
  const std::string& test = "hello";
  EXPECT_EQ(CtCI::StringIsUnique1(test), false);
}

TEST_F(_1_1_test, 2nonRepeating) {
  const std::string& test = "hey";
  EXPECT_EQ(CtCI::StringIsUnique2(test), true);
}
TEST_F(_1_1_test, 2nullString) {
  const std::string& test = "";
  EXPECT_EQ(CtCI::StringIsUnique2(test), true);
}
TEST_F(_1_1_test, 2repeatingString) {
  const std::string& test = "hello";
  EXPECT_EQ(CtCI::StringIsUnique2(test), false);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

