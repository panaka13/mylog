#include <iostream>

#include "constants.h"

namespace mylog {

  void set_log(std::ostream os);

  std::ostream & log(int level);

  void filter_log(int level);

} // namespace mylog
