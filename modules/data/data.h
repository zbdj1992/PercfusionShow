/**
* data.h
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef DATA_H
#define DATA_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <lcm/lcm-cpp.hpp>
#include "modules/data/lcm_util/lcmrecv_handler.h"
namespace percfusion_show {
namespace data {
class Data
{
public:
    Data();
public:
    static Data *get_obj() {
        static Data data_obj;
        return &data_obj;
    }
public:
    int init();
    int process();
    cv::Mat& get_img();
private:
    int lcm_listen(const std::string &channel);
    cv::Mat _frame;
    lcm::LCM _lcm_obj;
    LcmRecvHandler _handle_obj;

};
}//namespace data
}//namespace percfusion_show
#endif // DATA_H
