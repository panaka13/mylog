#pragma once

#include <iostream>

#include "base_logger.h"
#include "constants.h"
#include "file_logger.h"

namespace mylog {

void set_log(std::ostream &);

void set_log(std::string);

void filter_log(int);

void debug(std::string);

void info(std::string);

void warn(std::string);

void error(std::string);

void fatal(std::string);

}  // namespace mylog
