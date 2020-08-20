/**
* timeFunc.h
* Author: zhubin
* Created on: 2018-09-14
* Modified on:2019-02-28 time.h->timeFunc.h
* Copyright (c) luchangzhineng. All Rights Reserved
*/
#pragma once
#include <time.h>

namespace auto_driving {
namespace common {
namespace time {
class TimeFunc
{
public: 
	TimeFunc();
	~TimeFunc();
private:
    clock_t _timestart;
    clock_t _timeend;
public:
    //LARGE_INTEGER _timer;
    //LONGLONG _timestart;
    //LONGLONG _timeend;
    //LONGLONG _clockfreq;
	//double _deltaT;
public:
    //LONGLONG StartTime(void);
    clock_t StartTime(void);
    //LONGLONG TerminateTime(void);   //µ¥Î»£ºus
    clock_t TerminateTime(void);
    //void WaitDeltaT(LONGLONG _deltaT);  //µÈ´ý_deltaTÊ±¼ä£¬µ¥Î»:us
    void WaitDeltaT(clock_t deltaT);

//    void getCurrentTime(string &currentTime);

};
}//namespace time
}//namespace common
}//namespace auto_driving
