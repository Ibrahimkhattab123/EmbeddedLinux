#include "backtrace.hpp"

void Backtrace::capture(std::string functionName) {
  functionNames.push_back(functionName);
}

void Backtrace::print() {
  std::cout << "Backtrace:" << std::endl;
  for (auto it = functionNames.rbegin(); it != functionNames.rend(); ++it) {
    std::cout << *it << std::endl;
  }
}

BacktraceTracker::BacktraceTracker(Backtrace &backtrace,
                                   std::string functionName)
    : backtrace(backtrace) {
  backtrace.capture(functionName);
  std::cout << "Entering " << functionName << std::endl;
}
