/**
* lcmrecv_handler.h
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#include "lcmrecv_handler.h"
#include "modules/conf/parameters.h"
#include "modules/common/common.h"
namespace percfusion_show {
namespace data {
int LcmRecvHandler::init()
{
    conf::Parameters *conf_obj = conf::Parameters::get_obj();
    if (conf_obj->_conf_img_channels == 3) {
        _frame.create(conf_obj->_conf_img_height,conf_obj->_conf_img_width,CV_8UC3);
    }else if (conf_obj->_conf_img_channels == 1) {
        _frame.create(conf_obj->_conf_img_height,conf_obj->_conf_img_width,CV_8UC1);
    }else{
        return RET_ERROR;
    }
    return RET_OK;
}
void LcmRecvHandler::handleMessage(const lcm::ReceiveBuffer *rbuf,
                                   const std::string &chan,
                                   const lcm_struct::Lcm_Struct *msg)
{
    conf::Parameters *conf_obj = conf::Parameters::get_obj();
    memcpy(_frame.ptr<uchar>(0),msg->img_data,
           conf_obj->_conf_img_height*conf_obj->_conf_img_width*conf_obj->_conf_img_channels);
}
}//namespace data
}//namespace percfusion_show
