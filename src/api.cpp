#include "api.h"

#include <memory>

#include "base_logger.h"
#include "file_logger.h"
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
  logger_ptr = std::make_shared<StreamLogger>(level, os);
}

void set_log(std::string filename) {
  int level = logger_ptr->get_level();
  logger_ptr = std::make_shared<FileLogger>(level, filename);
}

void filter_log(int level) { logger_ptr->set_level(level); }
}  // namespace mylog
