#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "constants.h"

namespace mylog {
class BaseLogger {
 protected:
  int level;
  int state;

 public:
  BaseLogger(int level) : level(level), state(rand()) {}

  virtual void log(int, std::string) = 0;

  int get_level() { return this->level; }

  void set_level(int level) { this->level = level; }
};
}  // namespace mylog
