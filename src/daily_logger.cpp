#include "daily_logger.h"

#include "util.h"

namespace mylog {
void DailyLogger::log(int level, std::string message) {
  if (this->level < level) return;
  init_output();
  formatter.log(message, os);
}

void DailyLogger::flush() { os.flush(); }

void DailyLogger::init_output() {
  Day now = std::chrono::duration_cast<Day>(
      std::chrono::system_clock::now().time_since_epoch());
  if (now != today) {
    std::stringstream ss;
    name.log("", ss);
    std::string a = ss.str();
    os = std::ofstream(join_path(this->directory, a));
    today = now;
  }
}
}  // namespace mylog
