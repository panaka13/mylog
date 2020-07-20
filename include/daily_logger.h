#pragma once

#include <chrono>
#include <fstream>

#include "base_logger.h"

using Day = std::chrono::duration<int, std::ratio<86400>>;

namespace mylog {
class DailyLogger : public BaseLogger {
 protected:
  std::string directory;
  Formatter name;
  std::ofstream os;
  Day today;

 public:
  DailyLogger(int level, std::string directory, std::string format,
              Formatter& formatter)
      : BaseLogger(level, formatter), directory(directory), name(format) {}
  DailyLogger(int level, std::string directory, std::string format)
      : BaseLogger(level), directory(directory), name(format) {}
  DailyLogger(int level) : DailyLogger(level, "./", "%Y_%m_%d") {}

  void log(int, std::string);
  void flush();

 protected:
  void init_output();
};
}  // namespace mylog
