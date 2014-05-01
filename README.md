ProfilerCpp
===========

A simple yet effective C++ profiler.

Usage:
-----
Clone repository inside your project.

Include header file, and add cpp file to your makefile.

Timer usage:
-----------
Enclose the code you want to time between _ProfilerCpp::timerStart("timer name")_ and _ProfilerCpp::timerStop("timer name")_, use _ProfilerCpp::dumpTimers(std::cout)_ to print out the results.

Timer is useful to figure out which part of your code takes the most of time to run...

**Example code:**
```cpp
#include "ProfilerCpp/profilerCpp.hpp"
#include <iostream>
int main() {
  unsigned short int i = 1;
  ProfilerCpp::timerStart("loop");
  while(i != 0) {
    ProfilerCpp::timerStart("counting");
    i++;
    ProfilerCpp::timerStop("counting");
    
    ProfilerCpp::timerStart("other code");
    // your other code here
    ProfilerCpp::timerStop("other code");
  }
  ProfilerCpp::timerStop("loop");
  ProfilerCpp::dumpTimers(std::cout);
}
```

**Output:**
```
Timer "loop" took 0.0285979 seconds.
Timer "counting" took 0.00636508 seconds.
Timer "other code" took 0.00647034 seconds.
```
