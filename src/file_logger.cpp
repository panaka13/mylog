#include "file_logger.h"

namespace mylog {
void FileLogger::log(int level, std::string message) {
  if (this->level < level) return;
  formatter.log(message, os);
}

void FileLogger::flush() { os.flush(); }
}  // namespace mylog
