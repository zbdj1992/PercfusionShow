/**
* process.h
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef PROCESS_H
#define PROCESS_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
namespace percfusion_show {
namespace process {
class Process
{
public:
    Process();
    static Process *get_obj() {
        static Process process_obj;
        return &process_obj;
    }
public:
    int init();
    int process();
};
}//namespace process
}//namespace percfusion_show

#endif // PROCESS_H
