#include <iostream>
#include <opencv2/opencv.hpp>
#include <superCam.h>

using namespace cv;
using namespace sc;

int main(int argc, char** argv )
{
    // char* lenaPath = "C:/Users/rodol/vscodeProjects/a/lenna.png";
    // sc::test();
    // cv::Mat image;
    // image = imread(lenaPath);
    // if ( !image.data )
    // {
    //     std::cout << "No image data \n";
    //     return -1;
    // }
    // auto imgData = image.data;
    // auto imgRows = image.rows;
    // auto imgCols = image.cols;
    // auto imgChannels = image.channels;
    // sc::process(imgData, imgRows, imgCols, imgChannels);

    // std::vector<std::string> strList = {"acd", "def", "ghi", "quarto", "aaaaaa"};
    // sortString(strList);
    // printStrings(strList);

    // cv::Mat rebuild(imgRows, imgCols, CV_8UC3, imgData);
    // namedWindow("Display Image", WINDOW_AUTOSIZE );
    // imshow("Display Image", rebuild);
    // waitKey(0);

    sc::mainGL();
    return 0;
}