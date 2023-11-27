#include "logger.hpp"

int main() {
  logger::Logger log;

  log.log(logger::LogLevel::DEBUG, "This is debug message");
  log.log(logger::LogLevel::ERROR, "This is error message");
  log.log(logger::LogLevel::FATAL, "This is fatal message");
  log.log(logger::LogLevel::INFO, "This is info message");
  log.log(logger::LogLevel::NOTICE, "This is notice message");
  log.log(logger::LogLevel::TRACE, "This is trace message");
  log.log(logger::LogLevel::WARNING, "This is warning message");

  log.dump();
  log.clear();
}