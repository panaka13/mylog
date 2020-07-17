#include "util.h"

#include "gtest/gtest.h"

TEST(UtilTest, TestJoinString) {
  ASSERT_EQ(mylog::join_path("/root/dir", "path"), "/root/dir/path");
  ASSERT_EQ(mylog::join_path("/root/dir/", "path"), "/root/dir/path");
  ASSERT_EQ(mylog::join_path("relative/dir/", "path"), "relative/dir/path");
  ASSERT_EQ(mylog::join_path("relative/dir", "path"), "relative/dir/path");
}
