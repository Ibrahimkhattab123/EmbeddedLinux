#include "logger.hpp"

std::stringstream logger::getCurrentTime() {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  struct std::tm timeInfo;
  gmtime_r(&currentTime, &timeInfo);   // thread safe function 

  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
                          now.time_since_epoch()) %
                      1000;

  std::stringstream ss;
  ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "."
     << milliseconds.count();
  return ss;
}

logger::LogEntry::LogEntry(LogLevel level, const std::string &message)
    : level(level), message(message) {}

void logger::Logger::log(LogLevel level, const std::string &message) {

  logs.emplace_back(level, message);
}

std::string logger::Logger::logLevelToString(logger::LogLevel level) {
  switch (level) {
  case LogLevel::TRACE:
    return "TRACE";
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::INFO:   
    return "INFO";
  case LogLevel::NOTICE:
    return "NOTICE";
  case LogLevel::WARNING:
    return "WARNING";
  case LogLevel::ERROR:
    return "ERROR";
  case LogLevel::FATAL:
    return "FATAL";
  default:
    return "UNOKWN";
  }

}


std::string logger::Logger::logLevelToColour(logger::LogLevel level) {

  switch (level) {
  case LogLevel::TRACE:
    return "\x1B[0m"; // Default colour
  case LogLevel::DEBUG:
    return "\x1B[0m";  
  case LogLevel::INFO:   
    return "\x1B[0m";  
  case LogLevel::NOTICE:
    return "\x1B[34m"; // blue
  case LogLevel::WARNING:
    return "\x1B[34m"; 
  case LogLevel::ERROR:
    return "\x1B[31m"; // red 
  case LogLevel::FATAL:
    return "\x1B[31m";
  default:
    return "UNOKWN";
  }
}
namespace logger
{
  void Logger::dump()
  {
    // Print log with color as [LogLevel] message
    // ANSI escape sequences
    for (const auto& entry: logs){
      std::cout << getCurrentTime().str()  << " : [" << logLevelToColour(entry.level) << logLevelToString(entry.level)
            << "\x1B[0m] " << logLevelToColour(entry.level)  << entry.message << "\x1B[0m] "
            << std::endl;
    }
  }
  
  void Logger::clear()
  {
    logs.clear();
  }
}