/**
* data.cpp
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#include "data.h"
#include "modules/common/common.h"
#include "modules/conf/parameters.h"
#include "modules/common/log/glogutil.h"
namespace percfusion_show {
namespace data {
Data::Data()
{

}
int Data::init()
{
    conf::Parameters *conf_obj = conf::Parameters::get_obj();
//    if (conf_obj->_conf_img_channels == 3) {
//        _frame.create(conf_obj->_conf_img_height,conf_obj->_conf_img_width,CV_8UC3);
//    }else if (conf_obj->_conf_img_channels == 1) {
//        _frame.create(conf_obj->_conf_img_height,conf_obj->_conf_img_width,CV_8UC1);
//    }else{
//        return RET_ERROR;
//    }
    _handle_obj.init();
    lcm_listen(conf_obj->_conf_lcm_chan_name);
    return RET_OK;
}
int Data::process()
{
    conf::Parameters *conf_obj = conf::Parameters::get_obj();
    int ret = _lcm_obj.handleTimeout(conf_obj->_conf_lcm_recv_timeout);
    if (ret == 0) {
        LOG(WARNING)<<"lcm recv timeout!";
    }
    _frame = _handle_obj.get_img();
    return RET_OK;
}
int Data::lcm_listen(const std::string &channel)
{
    _lcm_obj.subscribe(channel,&LcmRecvHandler::handleMessage,&_handle_obj);
    return RET_OK;
}
cv::Mat& Data::get_img()
{
    return _frame;
}
}//namespace data
}//namespace percfusion_show
