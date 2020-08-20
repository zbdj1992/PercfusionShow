/**
* time.h
* Author: zhubin
* Created on: 2019-06-04
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef TIMER_H
#define TIMER_H
#include <ctime>
#include <limits>
namespace auto_driving {
namespace common {
namespace time {
class Timer
{
public:
    Timer() { _start_time = std::clock();}
     // return elapsed time in seconds,no-thread safe
    double elapsed() const { return  double(std::clock() - _start_time) / CLOCKS_PER_SEC; }
    // return minimum value for elapsed()
    double elapsed_min() const { return double(1)/double(CLOCKS_PER_SEC); }
    // return estimated maximum value for elapsed()
    double elapsed_max() const {
      return (double((std::numeric_limits<std::clock_t>::max)())
         - double(_start_time)) / double(CLOCKS_PER_SEC);
    }
private:
    std::clock_t _start_time;
};


}//namespace time
}//namespace common
}//namespace auto_driving
#endif // TIMER_H
