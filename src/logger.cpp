#include "logger.h"

std::shared_ptr<mylog::Logger> instance_ptr;

namespace mylog {
  void mylog::Logger::log(int level, std::string message) {
    if (this->level < level) 
      return;
    this->os << message << std::endl;
  }

  std::shared_ptr<Logger> Logger::get_logger() {
    if (instance_ptr == nullptr) 
      instance_ptr = std::make_shared<Logger>(ALL);
    return instance_ptr;
  }

  std::shared_ptr<Logger> Logger::create_logger(int level, std::ostream &os) {
    instance_ptr = std::make_shared<Logger>(level, os);
    return instance_ptr;
  }

  std::shared_ptr<Logger> Logger::create_logger(int level, std::ostream &&os) {
    instance_ptr = std::make_shared<Logger>(level, os);
    return instance_ptr;
  }
}
