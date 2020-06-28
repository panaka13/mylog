#include "gtest/gtest.h"
#include "timer.h"

TEST(TimerTestSuite, CaptureTime) {
  mylog::Timer timer;
  std::time_t actual_time = std::time(nullptr);
  timer.capture_time();
  std::tm tm_obj;
  tm_obj.tm_hour = timer.hour;
  tm_obj.tm_min = timer.minute;
  tm_obj.tm_sec = timer.second;
  tm_obj.tm_year = timer.year;
  tm_obj.tm_mon = timer.month - 1;
  tm_obj.tm_mday = timer.day;
  tm_obj.tm_wday = timer.day_of_week;
  std::time_t test_time = std::mktime(&tm_obj);
  ASSERT_LT(std::difftime(test_time, actual_time), 5);
}

