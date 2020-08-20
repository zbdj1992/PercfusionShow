QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    modules/conf/parameters.cpp \
    modules/common/log/glogutil.cpp \
    modules/data/data.cpp \
    modules/data/lcm_util/lcmrecv_handler.cpp \
    modules/process/process.cpp

HEADERS += \
    modules/conf/parameters.h \
    modules/common/readyaml/readyaml.h \
    modules/common/common.h \
    modules/common/log/glogutil.h \
    modules/data/data.h \
    modules/data/lcm_util/lcmrecv_handler.h \
    modules/process/process.h \
    modules/data/lcm_util/lcm_struct/Lcm_Struct.hpp
# x86_64
# aarch64
#GLOG
INCLUDEPATH += /usr/local/include/glog
LIBS        += /usr/local/lib/libglog.so
# GTEST
INCLUDEPATH += /usr/include/gtest
LIBS        += /usr/local/lib/libgtest.a
#Eigen
INCLUDEPATH += /usr/include/eigen3
#LCM
INCLUDEPATH += /usr/local/include/lcm
LIBS        += /usr/local/lib/liblcm.so
##aarch64-linux-gnu
##opencv
#unix:!macx: LIBS += -L$$PWD/3rdlib/opencv/lib/ -lopencv_core3 -lopencv_highgui3 -lopencv_imgproc3 \
#                    -lopencv_video3 -lopencv_imgcodecs3 -lopencv_videoio3 -lopencv_videostab3

#INCLUDEPATH += $$PWD/3rdlib/opencv/include \
#               $$PWD/3rdlib/opencv/include/opencv \
#               $$PWD/3rdlib/opencv/include/opencv2
#DEPENDPATH += $$PWD/3rdlib/opencv/include \
#               $$PWD/3rdlib/opencv/include/opencv \
#               $$PWD/3rdlib/opencv/include/opencv2
##protobuf3.7.1
#INCLUDEPATH += /usr/protobuf/include
#LIBS += /usr/protobuf/lib/libprotobuf.so\
#        /usr/protobuf/lib/libprotobuf-lite.so \
#        /usr/protobuf/lib/libprotoc.so
##boost
#INCLUDEPATH += /usr/include/boost
#LIBS +=/usr/lib/aarch64-linux-gnu/libboost_thread.a
#LIBS +=/usr/lib/aarch64-linux-gnu/libboost_system.a
#LIBS +=/usr/lib/aarch64-linux-gnu/libboost_chrono.a
#LIBS +=/usr/lib/aarch64-linux-gnu/libboost_date_time.a
##YAML
#INCLUDEPATH += /usr/include/yaml-cpp
#LIBS        += /usr/lib/aarch64-linux-gnu/libyaml*.so
##Vtk
#INCLUDEPATH +=/usr/include/vtk-6.2
#LIBS += /usr/lib/aarch64-linux-gnu/libvtk*.so
##PCL
#INCLUDEPATH += /usr/include/pcl-1.7
#LIBS        += /usr/lib/aarch64-linux-gnu/libpcl_*.so

#aarch64-linux-gnu

#x86_64-linux-gnu
#protobuf3.7.1
INCLUDEPATH += /usr/local/protobuf-3.7.1/include
LIBS += /usr/local/protobuf-3.7.1/lib/libprotobuf.so \
        /usr/local/protobuf-3.7.1/lib/libprotobuf-lite.so \
        /usr/local/protobuf-3.7.1/lib/libprotoc.so
#boost
INCLUDEPATH += /usr/include/boost
LIBS +=/usr/lib/x86_64-linux-gnu/libboost_thread.a
LIBS +=/usr/lib/x86_64-linux-gnu/libboost_system.a
LIBS +=/usr/lib/x86_64-linux-gnu/libboost_chrono.a
LIBS +=/usr/lib/x86_64-linux-gnu/libboost_date_time.a
#YAML
INCLUDEPATH += /usr/include/yaml-cpp
LIBS        += /usr/lib/x86_64-linux-gnu/libyaml*.so
#Vtk
INCLUDEPATH +=/usr/include/vtk-6.2
LIBS += /usr/lib/x86_64-linux-gnu/libvtk*.so
#PCL
INCLUDEPATH += /usr/include/pcl-1.7
LIBS        += /usr/lib/x86_64-linux-gnu/libpcl_*.so
#opencv
INCLUDEPATH += /usr/local/include/opencv \
               /usr/local/include/opencv2
LIBS        += /usr/local/lib/libopencv_core.so \
               /usr/local/lib/libopencv_highgui.so \
               /usr/local/lib/libopencv_imgproc.so \
               /usr/local/lib/libopencv_video.so
##x86_64-linux-gnu
DISTFILES += \
    modules/conf/conf.yaml
