#include "stream_logger.h"

namespace mylog {
void StreamLogger::log(int level, std::string message) {
  if (this->level < level) return;
  os << message << std::endl;
}
}  // namespace mylog
