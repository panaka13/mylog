#include "api.h"

namespace mylog {
  void debug(std::string message) {
    Logger::get_logger()->log(DEBUG, message);
  }

  void info(std::string message) {
    Logger::get_logger()->log(INFO, message);
  }

  void warn(std::string message) {
    Logger::get_logger()->log(WARN, message);
  }

  void error(std::string message) {
    Logger::get_logger()->log(ERROR, message);
  }

  void fatal(std::string message) {
    Logger::get_logger()->log(FATAL, message);
  }
}
