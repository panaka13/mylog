#include "formatter.h"

#include <iostream>
#include <sstream>
#include <thread>

namespace mylog {
std::stringstream Formatter::ss = std::stringstream();

void Formatter::set_precision(int precision) {
  Formatter::ss.precision(precision);
}

Formatter::Formatter() { set_format("[%Y/%m/%d %H:%M:%S.%i] %l\n"); }

void Formatter::log(std::string message, std::ostream &os) {
  if (not parsed) parse();
  this->message = message;
  timer.capture_time();
  for (auto &function : fs) os << function();
}

std::string Formatter::write_message() { return message; }

std::string Formatter::thread_id() {
  std::ostringstream os;
  os << std::this_thread::get_id();
  return os.str();
}

std::string Formatter::year() { return std::to_string(timer.year); }

std::string Formatter::month() {
  return (timer.month < 10 ? "0" : "") + std::to_string(timer.month);
}

std::string Formatter::day() {
  return (timer.day < 10 ? "0" : "") + std::to_string(timer.day);
}

std::string Formatter::hour() {
  return (timer.hour < 10 ? "0" : "") + std::to_string(timer.hour);
}

std::string Formatter::minute() {
  return (timer.minute < 10 ? "0" : "") + std::to_string(timer.minute);
}

std::string Formatter::second() {
  return (timer.second < 10 ? "0" : "") + std::to_string(timer.second);
}

std::string Formatter::millisecond() {
  return (timer.millisecond < 10 ? "0" : "") +
         std::to_string(timer.millisecond);
}

std::function<std::string()> Formatter::const_string(std::string str) {
  return [=]() -> std::string { return str; };
}

void Formatter::set_format(std::string format) {
  this->format = format;
  this->parsed = false;
}

void Formatter::parse() {
  parsed = true;
  std::string current = "";
  fs.clear();
  bool flag = false;
  for (auto ch : format) {
    if (flag) {
      factory_function(ch);
      flag = false;
    } else {
      if (ch == '%') {
        fs.push_back(const_string(current));
        flag = true;
        current.clear();
      } else {
        current.push_back(ch);
      }
    }
  }
  if (current.size() != 0) fs.push_back(const_string(current));
}

void Formatter::factory_function(char ch) {
  switch (ch) {
    case '%':
      fs.push_back(this->const_string("%"));
      break;
    case 'Y':
      fs.push_back([this]() -> std::string { return this->year(); });
      break;
    case 'm':
      fs.push_back([this]() -> std::string { return this->month(); });
      break;
    case 'd':
      fs.push_back([this]() -> std::string { return this->day(); });
      break;
    case 'H':
      fs.push_back([this]() -> std::string { return this->hour(); });
      break;
    case 'M':
      fs.push_back([this]() -> std::string { return this->minute(); });
      break;
    case 'S':
      fs.push_back([this]() -> std::string { return this->second(); });
      break;
    case 'i':
      fs.push_back([this]() -> std::string { return this->millisecond(); });
      break;
    case 'l':
      fs.push_back([this]() -> std::string { return this->write_message(); });
      break;
  }
}

std::string Formatter::str() {
  std::string ans;
  for (auto fn : fs) ans.insert(ans.size(), fn());
  return ans;
}
}  // namespace mylog
