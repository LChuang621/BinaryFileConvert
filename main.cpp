#include <iostream>
#include <opencv2/opencv.hpp>
#include<fstream>

int MAX_DIST = 15000;

bool Read_binary(std::string file_name, std::string save_name, int image_width, int images_height, int mat_size)
{
    FILE* fp = fopen(file_name.c_str(), "rb");
    if (fp == NULL) {
        std::cout << "not open" << std::endl;
        return false;
    }

    if (mat_size == 8)
    {
        cv::Mat ir_image(images_height, image_width, CV_8UC1);
        char* pdata = (char*)ir_image.data;
        std::cout << fread(pdata, 1, image_width * images_height, fp) << std::endl;
        fclose(fp);
        //std::string colorfilename = "binary_ir.png";
        cv::imwrite(save_name, ir_image);
    }
    else if (mat_size == 16)
    {
        cv::Mat depth_image(images_height, image_width, CV_16UC1);
        char* pdata = (char*)depth_image.data;
        std::cout << fread(pdata, 2, image_width * images_height, fp) << std::endl;
        fclose(fp);
        cv::imwrite(save_name, depth_image);
    }
    else if (mat_size == 32)
    {
        cv::Mat depth_image(images_height, image_width, CV_16UC1);
        char* pdata = (char*)depth_image.data;
        std::cout << fread(pdata, 2, image_width * images_height, fp) << std::endl;
        fclose(fp);
        cv::Mat QDepth8(depth_image.cols, depth_image.rows, CV_8UC1);
        depth_image.convertTo(QDepth8, CV_8UC1, 255.0 / MAX_DIST);
        cv::Mat QDepthRender;
        cv::applyColorMap(QDepth8, QDepthRender, 2);//2
        cv::cvtColor(QDepthRender, QDepthRender, cv::COLOR_RGB2BGR);
        cv::imwrite(save_name, QDepthRender);
    }
    else
    {
        return false;
    }
    return true;
}



#if 1
int main()
{
    //Read_binary("ir_data", "camera_depth.png", 1280, 800, 8);

    Read_binary("depth_data", "camera_depth.png", 640, 400, 16);
    Read_binary("depth_data", "camera_depth_8.png", 640, 400, 32);
    //Read_binary("depth2_frame.dat", "test_depth2.png", 640, 400, 16);



    return 0;
}
#endif
