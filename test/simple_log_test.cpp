#include <fstream>
#include <iostream>
#include <sstream>

#include "api.h"
#include "gtest/gtest.h"

TEST(SimpleTestSuite, TestSimpleLog) {
  mylog::info("INFO");
  mylog::warn("WARN");
  mylog::debug("DEBUG");
  mylog::fatal("FATAL");
  mylog::error("ERROR");
}

TEST(SimpleTestSuite, TestFileOutput) {
  mylog::set_log("tmp");
  mylog::set_format("%l\n");
  mylog::info("INFO");
  mylog::warn("WARN");
  mylog::debug("DEBUG");
  mylog::fatal("FATAL");
  mylog::error("ERROR");
  mylog::flush();
  std::ifstream input("tmp");
  std::string s;
  input >> s;
  ASSERT_EQ(s, "INFO");
  input >> s;
  ASSERT_EQ(s, "WARN");
  input >> s;
  ASSERT_EQ(s, "DEBUG");
  input >> s;
  ASSERT_EQ(s, "FATAL");
  input >> s;
  ASSERT_EQ(s, "ERROR");
}

TEST(SimpleTestSuite, TestStringStream) {
  std::stringstream ss;
  mylog::set_log(ss);
  mylog::set_format("%l\n");
  mylog::info("INFO");
  mylog::warn("WARN");
  mylog::debug("DEBUG");
  mylog::fatal("FATAL");
  mylog::error("ERROR");
  std::string s = ss.str();
  ASSERT_EQ(s, "INFO\nWARN\nDEBUG\nFATAL\nERROR\n");
}
