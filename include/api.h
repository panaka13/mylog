#pragma once

#include <iostream>
#include <sstream>

#include "base_logger.h"
#include "constants.h"
#include "file_logger.h"
#include "formatter.h"

namespace mylog {

void set_log(std::ostream &);

void set_log(std::string);

void filter_log(int);

std::shared_ptr<BaseLogger> get_logger_ptr();

template <class T>
void debug(T message) {
  std::string converted_message = Formatter::convert(message);
  get_logger_ptr()->log(DEBUG, converted_message);
}

template <class T>
void info(T message) {
  std::string converted_message = Formatter::convert(message);
  get_logger_ptr()->log(INFO, converted_message);
}

template <class T>
void warn(T message) {
  std::string converted_message = Formatter::convert(message);
  get_logger_ptr()->log(WARN, converted_message);
}

template <class T>
void error(T message) {
  std::string converted_message = Formatter::convert(message);
  get_logger_ptr()->log(ERROR, converted_message);
}

template <class T>
void fatal(T message) {
  std::string converted_message = Formatter::convert(message);
  get_logger_ptr()->log(FATAL, converted_message);
}

void set_format(std::string);

void flush();

void set_precision(int);

void daily_log(std::string, std::string = "%Y_%m_%d.log");

}  // namespace mylog
