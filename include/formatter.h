#pragma once

#include <functional>
#include <string>
#include <vector>

#include "timer.h"

namespace mylog {
class Formatter {
 protected:
  std::vector<std::function<std::string()>> fs;
  std::string format;
  std::string message;
  Timer timer;
  bool parsed; 

 public:
  Formatter();
  Formatter(Formatter& other) : format(other.format), timer(other.timer) {
    this->parse();
  }
  void log(std::string, std::ostream&);
  void set_format(std::string);

 protected:
  std::string write_message();
  std::string day();
  std::string month();
  std::string year();
  std::string year_two_digit();
  std::string hour();
  std::string minute();
  std::string second();
  std::string millisecond();
  std::string thread_id();
  std::string process_id();
  std::function<std::string()> const_string(std::string);
  void parse();
  void factory_function(char);
};
}  // namespace mylog
