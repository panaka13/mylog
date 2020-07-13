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

 public:
  BaseLogger(int level) : level(level), formatter() {}
  BaseLogger(int level, Formatter& formatter)
      : level(level), formatter(formatter) {}
  void set_format(std::string format) { formatter.set_format(format); }
  virtual void log(int, std::string) = 0;
  virtual void flush() = 0;
  int get_level() { return this->level; }
  void set_level(int level) { this->level = level; }
  Formatter get_format() { return this->formatter; }
};
}  // namespace mylog
