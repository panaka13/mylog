#include "timer.h"

#include <cstdio>

#include "gtest/gtest.h"

int num_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long get_tick_count(mylog::Timer &x) {
  long long ans = 0;
  for (int i = 1; i < x.year; i++) ans += 365 + mylog::Timer::is_leap_year(i);
  for (int i = 0; i < x.month - 1; i++) ans += num_day_of_month[i];
  ans += x.day - 1;
  ans = ((ans * 24 + x.hour) * 60 + x.minute) * 60 + x.second;
  return ans;
}

long long get_tick_count(std::tm &x) {
  long long ans = 0;
  for (int i = 1; i < x.tm_year + 1900; i++)
    ans += 365 + mylog::Timer::is_leap_year(i);
  for (int i = 0; i < x.tm_mon; i++) ans += num_day_of_month[i];
  ans += x.tm_mday - 1;
  ans = ((ans * 24 + x.tm_hour) * 60 + x.tm_min) * 60 + x.tm_sec;
  return ans;
}

long long compare(mylog::Timer &x, std::tm &y) {
  return get_tick_count(x) - get_tick_count(y);
}

TEST(TimerTestSuite, CaptureTimeUTC) {
  mylog::Timer timer(0);
  std::time_t actual_local_time = std::time(nullptr);
  timer.capture_time();
  std::tm actual_utc_tm = *std::gmtime(&actual_local_time);
  long long diff = compare(timer, actual_utc_tm);
  ASSERT_LT(std::abs(diff), 1);
}

TEST(TimerTestSuite, CaptureLocalTime) {
  mylog::Timer timer;
  timer.capture_time();
  std::time_t actual_local_time = std::time(nullptr);
  std::tm actual_local_tm = *std::localtime(&actual_local_time);
  long long diff = compare(timer, actual_local_tm);
  ASSERT_LT(std::abs(diff), 1);
}

TEST(TimerTestSuite, LeapYearTest) {
  ASSERT_TRUE(mylog::Timer::is_leap_year(2000));
  ASSERT_TRUE(mylog::Timer::is_leap_year(2004));
  ASSERT_FALSE(mylog::Timer::is_leap_year(1900));
  ASSERT_FALSE(mylog::Timer::is_leap_year(2002));
}
