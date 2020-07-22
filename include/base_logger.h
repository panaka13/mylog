#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "constants.h"
#include "formatter.h"

namespace mylog {
class BaseLogger {
 protected:
  int level;
  Formatter formatter;
  bool append;

 public:
  BaseLogger(int level, bool append = false)
      : level(level), formatter(), append(append) {}
  BaseLogger(int level, Formatter& formatter, bool append = false)
      : level(level), formatter(formatter), append(append) {}
  void set_format(std::string format) { formatter.set_format(format); }
  int get_level() { return this->level; }
  void set_level(int level) { this->level = level; }
  Formatter get_format() { return this->formatter; }
  bool append_mode() { return this->append; }

  virtual void log(int, std::string) = 0;
  virtual void flush() = 0;
};
}  // namespace mylog
