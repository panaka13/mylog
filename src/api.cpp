#include "api.h"

#include <chrono>
#include <iomanip>
#include <memory>
#include <sstream>

#include "base_logger.h"
#include "file_logger.h"
#include "formatter.h"
#include "stream_logger.h"

namespace mylog {

std::shared_ptr<BaseLogger> logger_ptr = std::make_shared<StreamLogger>();

std::shared_ptr<BaseLogger> get_logger_ptr() { return logger_ptr; }

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

void set_precision(int precision) { Formatter::set_precision(precision); }
}  // namespace mylog
