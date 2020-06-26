#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "constants.h"

namespace mylog {
class Logger {
 protected:
  int level;
  std::ostream os;

 public:
  Logger(int level) : level(level), os(std::cout.rdbuf()) {}
  Logger(int level, std::string filename)
      : level(level), os(std::ofstream(filename).rdbuf()) {}
  Logger(int level, std::ostream &os) : level(level), os(os.rdbuf()) {}

  ~Logger() { os.flush(); }

  static std::shared_ptr<Logger> get_logger();

  static std::shared_ptr<Logger> create_logger(int, std::ostream &);

  static std::shared_ptr<Logger> create_logger(int, std::ostream &&);

  static std::shared_ptr<Logger> create_logger(int level) {
    return create_logger(level, std::cout);
  }

  static std::shared_ptr<Logger> create_logger(int level,
                                               std::string filename) {
    return create_logger(level, std::ofstream(filename));
  }

  void log(int, std::string);

  int get_level() { return this->level; }

  void set_level(int level) { this->level = level; }
};
}  // namespace mylog
