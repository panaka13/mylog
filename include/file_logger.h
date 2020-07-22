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
  FileLogger(int level, std::string filename, bool append = false)
      : BaseLogger(level, append),
        os(filename, append ? std::ios_base::app | std::ios_base::out
                            : std::ios_base::out) {}
  FileLogger(int level, std::ofstream &os)
      : BaseLogger(level), os(std::move(os)) {}
  FileLogger(int level, std::string filename, Formatter &formatter,
             bool append = false)
      : BaseLogger(level, formatter, append),
        os(filename, append ? std::ios_base::app | std::ios_base::out
                            : std::ios_base::out) {}

  ~FileLogger() { os.flush(); }

  void log(int, std::string);
  void flush();
};
}  // namespace mylog
