#pragma once

#include <cxxabi.h>
#include <iostream>
#include <string>
#include <vector>

class Backtrace {
public:
  Backtrace() {}

  void capture(std::string functionName);

  void print();

private:
  std::vector<std::string> functionNames;
};

class BacktraceTracker {
public:
  BacktraceTracker(Backtrace &backtrace, std::string functionName);
  ~BacktraceTracker() { std::cout << "Leaving " << functionName << std::endl; }

private:
  Backtrace &backtrace;
  std::string functionName;
};