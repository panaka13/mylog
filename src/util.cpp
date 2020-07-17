#include "util.h"

#include <cassert>

namespace mylog {
std::string join_path(std::string &&a, std::string &&b) {
  assert(b.front() != '/');
  if (a.back() == '/')
    return a + b;
  else
    return a + "/" + b;
}

std::string join_path(std::string &a, std::string &b) {
  assert(b.front() != '/');
  if (a.back() == '/')
    return a + b;
  else
    return a + "/" + b;
}
}  // namespace mylog
