#include "api.h"
#include "configure.h"
#include "daily_logger.h"
#include "file_test_handler.h"
#include "formatter.h"
#include "gtest/gtest.h"
#include "util.h"

TEST_F(FileHandlerTest, SimpleDailyLogTest) {
  std::string test_directory = mylog::join_path(BUILD_DIRECTORY, "tmp_dir");
  std::string format = "%Y_%m_%d.log";
  mylog::set_format("%l ");
  mylog::daily_log(test_directory, format);
  mylog::info("Info Log");
  mylog::debug("Debug Log");
  mylog::flush();
  mylog::Formatter formatter(format);
  std::stringstream ss;
  formatter.log("", ss);
  std::ifstream infile(mylog::join_path(std::move(test_directory), ss.str()));
  std::string message;
  std::getline(infile, message);
  ASSERT_EQ(message, "Info Log Debug Log ");
  infile.close();
}

TEST_F(FileHandlerTest, HelloSword) {}
