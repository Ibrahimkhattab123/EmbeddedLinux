#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace logger {
std::stringstream getCurrentTime();
enum class LogLevel { TRACE, DEBUG, INFO, NOTICE, WARNING, ERROR, FATAL };

// a class to store the log enteries
struct LogEntry {
  LogLevel level;
  std::string message;
  

  LogEntry(LogLevel level, const std::string &message);
};

class Logger {
public:
  Logger() {}

  void log(LogLevel level, const std::string &message);

  void dump();

  void clear();

private:
  std::vector<LogEntry>
      logs; // to store the enteries for debugging or reports and so on

  std::string  logLevelToString(logger::LogLevel level);
  std::string  logLevelToColour(logger::LogLevel level);

  std::string levelStr = "";
  std::string colorCode = "";

};
} // namespace logger