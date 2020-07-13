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
