#include <services/image_handler.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <string>

cv::Mat imagehandler::Import(std::string path){
    cv::samples::findFile(path);

    cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);

    return image;
};

void imagehandler::Display(cv::Mat image){
    cv::imshow("Display window", image);

    int user_key = cv::waitKey(0);
};