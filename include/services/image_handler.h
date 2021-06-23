#ifndef TLC_INCLUDE_SERVICES_IMAGE_HANDLER_H
#define TLC_INCLUDE_SERVICES_IMAGE_HANDLER_H

#include <opencv2/core.hpp>

#include<string>

namespace imagehandler {
    cv::Mat Import(std::string path);
    void Display(cv::Mat image);
};

#endif