/**
* timeFunc.cpp
* Author: zhubin
* Created on: 2018-09-14
* Modified on:2019-02-28 time.h->timeFunc.cpp
* Copyright (c) luchangzhineng. All Rights Reserved
*/
#include "timeFunc.h"
#include "modules/common/common.h"
namespace auto_driving {
namespace common {
namespace time {
	TimeFunc::TimeFunc()
	{
		_timestart=0;
		_timeend=0;
	}
	TimeFunc::~TimeFunc()
	{

	}
    clock_t TimeFunc::StartTime()
	{
        _timestart = clock();
		return _timestart;
	}
    clock_t TimeFunc::TerminateTime()
	{
        _timeend = clock();
		return (_timeend-_timestart);
	}
    void TimeFunc::WaitDeltaT(clock_t _deltaT)  //_deltTµ¥Î»us
	{
        clock_t timeStart = 0;
        clock_t timeEnd = 0;
        timeStart = clock();
        do{
           timeEnd = clock();
        }while((timeEnd-timeStart)<=_deltaT);
	}

}//namespace time
}//namespace common
}//namespace auto_driving
