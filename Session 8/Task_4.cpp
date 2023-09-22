#include "backtrace.hpp"

// creates an instance of BacktraceTracker with the unique variable name and the
// current function's name (__PRETTY_FUNCTION__).
//#define TRACE_FUNCTION(backtrace) BacktraceTracker
// trace_##__COUNTER__(backtrace, __PRETTY_FUNCTION__)
#define TRACE_FUNCTION(backtrace)                                              \
  BacktraceTracker tracker(backtrace, __PRETTY_FUNCTION__);

void innerFunction(Backtrace &backtrace) { TRACE_FUNCTION(backtrace); }

void middleFunction(Backtrace &backtrace) {
  TRACE_FUNCTION(backtrace);
  innerFunction(backtrace);
}

void outerFunction(Backtrace &backtrace) {
  TRACE_FUNCTION(backtrace);
  middleFunction(backtrace);
}

int main() {
  Backtrace backtrace;
  outerFunction(backtrace);

  backtrace.print();

  return 0;
}