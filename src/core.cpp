#include "api.h"

namespace mylog {

  void set_log(std::ostream) {
    std::cout << "new output stream for logging" << std::endl;
  }

  void filter_log(int level) {
    std::cout << "filter log level " << level << std::endl;
  }

  std::ostream & log(int level) {
    return std::cout;
  }

}
