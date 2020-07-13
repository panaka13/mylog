#include "api.h"

#include <chrono>
#include <iomanip>
#include <memory>

#include "base_logger.h"
#include "file_logger.h"
#include "formatter.h"
#include "stream_logger.h"

namespace mylog {

std::shared_ptr<BaseLogger> logger_ptr = std::make_shared<StreamLogger>();

void debug(std::string message) { logger_ptr->log(DEBUG, message); }

void info(std::string message) { logger_ptr->log(INFO, message); }

void warn(std::string message) { logger_ptr->log(WARN, message); }

void error(std::string message) { logger_ptr->log(ERROR, message); }

void fatal(std::string message) { logger_ptr->log(FATAL, message); }

void set_log(std::ostream &os) {
  int level = logger_ptr->get_level();
  Formatter formatter = logger_ptr->get_format();
  logger_ptr = std::make_shared<StreamLogger>(level, os, formatter);
}

void set_log(std::string filename) {
  int level = logger_ptr->get_level();
  Formatter formatter = logger_ptr->get_format();
  logger_ptr = std::make_shared<FileLogger>(level, filename, formatter);
}

void filter_log(int level) { logger_ptr->set_level(level); }

void set_format(std::string str) { logger_ptr->set_format(str); }

void flush() { logger_ptr->flush(); }
}  // namespace mylog
