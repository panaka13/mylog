#include <functional>
#include <string>
#include <vector>

#include "timer.h"

namespace mylog {
class Formatter {
 protected:
  std::vector<std::function<std::string()>> fs;
  std::string message;
  Timer timer;

 public:
  Formatter();
  void log(std::string, std::ostream &);
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
  void factory_function(char);
};
}  // namespace mylog
