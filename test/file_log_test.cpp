#include <fstream>
#include <iostream>
#include <sstream>

#include "api.h"
#include "file_test_handler.h"
#include "gtest/gtest.h"

TEST(FileTestSuite, TestFileOutput) {
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

TEST_F(FileHandlerTest, TestAppendFileOut) {
  std::string log_file =
      mylog::join_path(BUILD_DIRECTORY, "tmp_dir/existing.log");
  std::ofstream output(log_file);
  output << "existing log\n";
  output.close();
  mylog::set_log(log_file, true);
  mylog::set_format("%l\n");
  mylog::info("info log");
  mylog::flush();
  std::ifstream input(log_file);
  std::string message;
  std::getline(input, message);
  ASSERT_EQ(message, "existing log");
  std::getline(input, message);
  ASSERT_EQ(message, "info log");
}
