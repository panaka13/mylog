#include "timer.h"

namespace mylog {

  int num_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  void Timer::capture_time() {
    auto now = std::chrono::system_clock::now();
    long long tick_count = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    this->millisecond = tick_count % 1000;
    tick_count /= 1000;
    this->second = tick_count % 60;
    tick_count /= 60;
    this->minute = tick_count % 60;
    tick_count /= 60;
    this->hour = tick_count % 24;
    tick_count /= 24;
    this->month = 0;
    this->day_of_week = (4 + tick_count) % 7;
    this->year = 1970;
    while (tick_count >= 365 + Timer::is_leap_year(this->year)) {
      tick_count -= 365 + Timer::is_leap_year(this->year);
      this->year += 1;
    }
    while (num_day_of_month[this->month] >= tick_count) {
      tick_count -= num_day_of_month[this->month];
      this->month += 1;
    }
    this->month += 1;
    this->day = 0 + tick_count;
  }
}
