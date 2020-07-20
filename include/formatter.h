#pragma once

#include <functional>
#include <sstream>
#include <string>
#include <vector>

#include "timer.h"

namespace mylog {
class Formatter {
  // Static part
 protected:
  static std::stringstream ss;

 public:
  template <class MesssageType>
  static std::string convert(MesssageType message) {
    ss << message;
    std::string ans = ss.str();
    ss.str(std::string());
    return ans;
  }
  static void set_precision(int);

 protected:
  std::vector<std::function<std::string()>> fs;
  std::string format;
  std::string message;
  Timer timer;
  bool parsed = false;

 public:
  Formatter();
  Formatter(std::string format) : format(format) {}
  Formatter(Formatter& other) : format(other.format), timer(other.timer) {}
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
  std::string str();
  std::function<std::string()> const_string(std::string);
  void parse();
  void factory_function(char);
};
}  // namespace mylog
