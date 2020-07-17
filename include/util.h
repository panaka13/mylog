#pragma once

#include <string>

namespace mylog {
std::string join_path(std::string &a, std::string &b);
std::string join_path(std::string &&a, std::string &&b);
}  // namespace mylog
