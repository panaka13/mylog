#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "base_logger.h"
#include "constants.h"

namespace mylog {
class FileLogger : public BaseLogger {
 protected:
  std::ofstream os;

 public:
  FileLogger(int level, std::string filename)
      : BaseLogger(level), os(filename) {}
  FileLogger(int level, std::ofstream &os)
      : BaseLogger(level), os(std::move(os)) {}
  FileLogger(int level, std::string filename, Formatter &formatter)
      : BaseLogger(level, formatter), os(filename) {}

  ~FileLogger() { os.flush(); }

  void log(int, std::string);
  void flush();
};
}  // namespace mylog
