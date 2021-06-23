#include <exercises/list/tenth.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

void TenthExercise::ExecQ1(){
    std::string resource_path = RESOURCE_FILE_DIR;
    std::string image_path = resource_path + "/images/Pedestrian.png";

    cv::samples::findFile(image_path);

    cv::Mat pedestrian_image = cv::imread(image_path, cv::IMREAD_COLOR);

    if(pedestrian_image.empty() == false){
        cv::imshow("Display window", pedestrian_image);

        int user_key = cv::waitKey(0);
    }else{
        std::cout << "Could not read the image: " << image_path;
    }
};