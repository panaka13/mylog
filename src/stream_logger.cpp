#include "stream_logger.h"

namespace mylog {
void StreamLogger::log(int level, std::string message) {
  if (this->level < level) return;
  formatter.log(message, os);
}

void StreamLogger::flush() { os.flush(); }
}  // namespace mylog
