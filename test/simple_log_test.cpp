#include "api.h"
#include "gtest/gtest.h"

TEST(SimpleTestSuite, TestSimpleLog) {
  mylog::info("INFO LOG");
  mylog::warn("WARN LOG");
  mylog::debug("DEBUG LOG");
  mylog::fatal("FATAL LOG");
  mylog::error("ERROR LOG");
}

TEST(SimpleTestSuite, TestFileOutput) {
  mylog::set_log("tmp");
  mylog::info("INFO LOG");
  mylog::warn("WARN LOG");
  mylog::debug("DEBUG LOG");
  mylog::fatal("FATAL LOG");
  mylog::error("ERROR LOG");
}
