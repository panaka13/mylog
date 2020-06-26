#include "file_logger.h"

namespace mylog {
void FileLogger::log(int level, std::string message) {
  if (this->level < level) return;
  this->os << message << std::endl;
}
}  // namespace mylog
