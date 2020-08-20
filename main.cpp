#include <QCoreApplication>
#include "modules/common/log/glogutil.h"
#include "modules/conf/parameters.h"
#include "modules/process/process.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string conf_file = "../modules/conf/conf.yaml";
    std::string log_path = "log";
    percfusion_show::common::GlogUtil::get_obj()->init(argv[0],log_path);
    percfusion_show::conf::Parameters::get_obj()->init(conf_file.c_str());
    percfusion_show::process::Process::get_obj()->process();
    return a.exec();
}
