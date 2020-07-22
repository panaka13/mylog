#pragma once

#include <chrono>
#include <fstream>

#include "file_logger.h"

using Day = std::chrono::duration<int, std::ratio<86400>>;

namespace mylog {
class DailyLogger : public FileLogger {
 protected:
  std::string directory;
  Formatter name;
  Day today;

 public:
  DailyLogger(int level, std::string directory, std::string format,
              Formatter& formatter, bool append = false)
      : FileLogger(level, "", formatter), directory(directory), name(format) {}
  DailyLogger(int level, std::string directory, std::string format,
              bool append = false)
      : FileLogger(level, ""), directory(directory), name(format) {}
  DailyLogger(int level, bool append = false)
      : DailyLogger(level, "./", "%Y_%m_%d", append) {}

  void log(int, std::string);
  void flush();

 protected:
  void init_output();
};
}  // namespace mylog
