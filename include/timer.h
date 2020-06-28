#pragma once

#include <chrono>

namespace mylog {

  struct Timer {
    int day, month, year;
    int hour, minute, second, millisecond;
    int day_of_week;

    void capture_time();

    static bool is_leap_year(int year) {
      if (year % 400 == 0)
        return true;
      if (year % 100 == 0)
        return false;
      return year % 4 == 0;
    }
  };

}
