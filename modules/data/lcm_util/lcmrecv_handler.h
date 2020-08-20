/**
* lcmrecv_handler.h
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef LCMRECV_HANDLER_H
#define LCMRECV_HANDLER_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "modules/data/lcm_util/lcm_struct/Lcm_Struct.hpp"
#include <lcm/lcm-cpp.hpp>
namespace percfusion_show {
namespace data {
class LcmRecvHandler
{
public:
    LcmRecvHandler() {}
    ~LcmRecvHandler() {}
public:
    int init();
    cv::Mat& get_img() {return _frame;}
public:
    void handleMessage(const lcm::ReceiveBuffer *rbuf,
                       const std::string &chan,
                       const lcm_struct::Lcm_Struct *msg);
private:
    cv::Mat _frame;
};
}//namespace data
}//namespace percfusion_show
#endif // LCMRECV_HANDLER_H
