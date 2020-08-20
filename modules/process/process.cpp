/**
* process.cpp
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#include "process.h"
#include "modules/data/data.h"
#include "modules/common/common.h"
namespace percfusion_show {
namespace process {
Process::Process()
{

}
int Process::init()
{
    data::Data* data_obj = data::Data::get_obj();
    data_obj->init();
    return RET_OK;
}
int Process::process()
{
    init();
    data::Data* data_obj = data::Data::get_obj();
    while (true) {
        data_obj->process();
        cv::Mat frame = data_obj->get_img();
        cv::imshow("percfusion_show",frame);
        cv::waitKey(1);
    }
    return RET_OK;
}
}//namespace process
}//namespace percfusion_show
