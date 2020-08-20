/**
* parameters.cpp
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#include "parameters.h"
#include "modules/common/readyaml/readyaml.h"
#include "modules/common/log/glogutil.h"
namespace percfusion_show {
namespace conf {
Parameters::Parameters()
{

}
int Parameters::init(const std::string &file_path)
{
    load_conf(file_path);
    return RET_OK;
}
int Parameters::load_conf(const std::string& file_path)
{
    common::ReadYaml readyaml;
    YAML::Node parma_node = readyaml.load_conf(file_path);
    int ret = 0;
    ret = readyaml.parse_yaml(parma_node,"img_width",this->_conf_img_width,1200);
    if (ret == RET_ERROR){
        LOG(FATAL)<<"img_width conf failed!";
    }else{
        LOG(INFO)<<"img_width conf successed!";
    }
    ret = readyaml.parse_yaml(parma_node,"img_height",this->_conf_img_height,400);
    if (ret == RET_ERROR){
        LOG(FATAL)<<"img_height conf failed!";
    }else{
        LOG(INFO)<<"img_height conf successed!";
    }
    ret = readyaml.parse_yaml(parma_node,"img_channels",this->_conf_img_channels,3);
    if (ret == RET_ERROR){
        LOG(FATAL)<<"img_channels conf failed!";
    }else{
        LOG(INFO)<<"img_channels conf successed!";
    }
    ret = readyaml.parse_yaml(parma_node,"lcm_recv_timeout",this->_conf_lcm_recv_timeout,100);
    if (ret == RET_ERROR){
        LOG(FATAL)<<"lcm_recv_timeout conf failed!";
    }else{
        LOG(INFO)<<"lcm_recv_timeout conf successed!";
    }
    std::string chan_name = "percfusion_show";
    ret = readyaml.parse_yaml(parma_node,"lcm_chan_name",this->_conf_lcm_chan_name,chan_name);
    if (ret == RET_ERROR){
        LOG(FATAL)<<"lcm_chan_name conf failed!";
    }else{
        LOG(INFO)<<"lcm_chan_name conf successed!";
    }
    return RET_OK;
}
}//namespace conf
}//namespace percfusion_show
