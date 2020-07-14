#include <fstream>
#include <iostream>
#include <sstream>

#include "api.h"
#include "gtest/gtest.h"

TEST(TypeLogTest, IntegerLogTest) {
  std::stringstream ss;
  mylog::set_format("%l\n");
  mylog::set_log(ss);
  mylog::info(123);
  mylog::info(1234567891011l);
  ASSERT_EQ(ss.str(), "123\n1234567891011\n");
}

TEST(TypeLogTest, FloatLogTest) {
  std::stringstream ss;
  mylog::set_precision(5);
  mylog::set_format("%l\n");
  mylog::set_log(ss);
  mylog::info(123.5);
  mylog::info(123.123456789);
  ASSERT_EQ(ss.str(), "123.5\n123.12\n");
}

struct MyClass {};

std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
  os << "My Class";
  return os;
}

TEST(TypeLogTest, UserDefineTypeTest) {
  std::stringstream ss;
  mylog::set_log(ss);
  mylog::set_format("%l\n");
  MyClass obj;
  mylog::info(obj);
  ASSERT_EQ(ss.str(), "My Class\n");
}
