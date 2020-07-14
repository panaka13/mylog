#pragma once

#include <iostream>
#include <sstream>

#include "base_logger.h"
#include "constants.h"
#include "file_logger.h"

namespace mylog {

void set_log(std::ostream &);

void set_log(std::string);

void filter_log(int);

std::shared_ptr<BaseLogger> get_logger_ptr();

template <class T>
void debug(T message) {
  std::stringstream ss;
  ss << message;
  get_logger_ptr()->log(DEBUG, ss.str());
}

template <class T>
void info(T message) {
  std::stringstream ss;
  ss << message;
  get_logger_ptr()->log(INFO, ss.str());
}

template <class T>
void warn(T message) {
  std::stringstream ss;
  ss << message;
  get_logger_ptr()->log(WARN, ss.str());
}

template <class T>
void error(T message) {
  std::stringstream ss;
  ss << message;
  get_logger_ptr()->log(ERROR, ss.str());
}

template <class T>
void fatal(T message) {
  std::stringstream ss;
  ss << message;
  get_logger_ptr()->log(FATAL, ss.str());
}

void set_format(std::string);

void flush();

}  // namespace mylog
