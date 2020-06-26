#include "api.h"

namespace mylog {
void debug(std::string message) { Logger::get_logger()->log(DEBUG, message); }

void info(std::string message) { Logger::get_logger()->log(INFO, message); }

void warn(std::string message) { Logger::get_logger()->log(WARN, message); }

void error(std::string message) { Logger::get_logger()->log(ERROR, message); }

void fatal(std::string message) { Logger::get_logger()->log(FATAL, message); }

void set_log(std::ostream &os) {
  int level = Logger::get_logger()->get_level();
  Logger::create_logger(level, os);
}

void set_log(std::string filename) {
  int level = Logger::get_logger()->get_level();
  Logger::create_logger(level, filename);
}

void filter_log(int level) { Logger::get_logger()->set_level(level); }
}  // namespace mylog
