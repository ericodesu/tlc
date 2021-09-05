#include <exercises/list/tenth.h>
#include <services/image_handler.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

void TenthExercise::execQ1(){
    std::string resource_path = RESOURCE_FILE_DIR;
    std::string image_path = resource_path + "/images/Pedestrian.png";

    cv::Mat pedestrian_image = imagehandler::import(image_path);

    if(pedestrian_image.empty() == false){
        imagehandler::display(pedestrian_image);

        for(int y = 0; y < pedestrian_image.rows; y++){
            for(int x = 0; x < pedestrian_image.cols; x++){
                cv::Vec3b &colors = pedestrian_image.at<cv::Vec3b>(y, x);

                int grey_scale_tolerance = 80,
                    R = colors[0],
                    G = colors[1],
                    B = colors[2];

                if(
                    R <= grey_scale_tolerance &&
                    G <= grey_scale_tolerance &&
                    B <= grey_scale_tolerance
                ){
                    colors[0] = 4;
                    colors[1] = 140;
                    colors[2] = 4;
                }

                pedestrian_image.at<cv::Vec3b>(cv::Point(x, y)) = colors;
            }
        }

        imagehandler::display(pedestrian_image);
    }else{
        std::cout << "Could not read the image: " << image_path;
    }
};