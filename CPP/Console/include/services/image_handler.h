#ifndef TLC_CPP_INCLUDE_SERVICES_IMAGE_HANDLER_H
#define TLC_CPP_INCLUDE_SERVICES_IMAGE_HANDLER_H

#include <opencv2/core.hpp>

#include<string>

namespace image_handler {
    cv::Mat import(std::string path);
    void display(cv::Mat image);
};

#endif