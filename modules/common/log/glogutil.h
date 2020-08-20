/**
* glogutil.h
* Author: zhubin
* Created on: 2019-05-31
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef GLOGUTIL_H
#define GLOGUTIL_H
#include <glog/logging.h>
#include <glog/raw_logging.h>
#include <string>
namespace percfusion_show {
namespace common {
class GlogUtil
{
public:
    GlogUtil();
    ~GlogUtil();
public:
    int init(char* program,const std::string log_path);  //GLOG配置
public:
    static GlogUtil* get_obj() {
        static GlogUtil glogutil_obj;
        return &glogutil_obj;
    }
};
}//namespace common
}//namespace percfusion_show
#endif // GLOGUTIL_H
