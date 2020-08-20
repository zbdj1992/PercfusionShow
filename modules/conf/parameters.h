/**
* parameters.h
* Author: zhubin
* Created on: 2019-10-29
* Copyright (c) iRotran. All Rights Reserved
*/
#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>
namespace percfusion_show {
namespace conf {
class Parameters
{
public:
    Parameters();
public:
    int init(const std::string& file_path);
public:
    static Parameters *get_obj() {
        static Parameters param_obj;
        return &param_obj;
    }
public:
    int _conf_img_width;
    int _conf_img_height;
    int _conf_img_channels;
    int _conf_lcm_recv_timeout;
    std::string _conf_lcm_chan_name;
private:
    int load_conf(const std::string& file_path);
};
}//namespace conf
}//namespace percfusion_show
#endif // PARAMETERS_H
