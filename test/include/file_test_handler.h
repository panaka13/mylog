#pragma once

#include <filesystem>

#include "configure.h"
#include "gtest/gtest.h"
#include "util.h"

class FileHandlerTest : public ::testing::Test {
 protected:
  std::string test_directory = mylog::join_path(BUILD_DIRECTORY, "tmp_dir");

 public:
  void SetUp() { std::filesystem::create_directory(test_directory); }
};
