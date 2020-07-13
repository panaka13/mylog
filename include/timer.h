#pragma once

#include <chrono>
#include <string>

#include "configure.h"

namespace mylog {

struct Timer {
  Timer() : timezone_offset(TIMEZONE * 3600 * 1000) {}
  Timer(int timezone) : timezone_offset(timezone * 3600 * 1000) {}
  Timer(const Timer& other) : timezone_offset(other.timezone_offset) {}
  Timer(Timer&& other) : timezone_offset(other.timezone_offset) {}

  int timezone_offset;
  int day, month, year;
  int hour, minute, second, millisecond;
  int day_of_week;

  void capture_time();

  static bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
  }
};
}  // namespace mylog
