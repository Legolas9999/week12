#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat img1 = imread("ren.jpg", 0);
    //灰度归一化
    Mat grayImg;
    img1.convertTo(grayImg, CV_64F, 1.0 / 255, 0);
    //伽马变换
    double gamma = 0.47;
    Mat gammaImg;
    pow(grayImg, gamma, gammaImg);
    gammaImg.convertTo(gammaImg, CV_8U, 255, 0);
    imshow("gammaImg.jpg", gammaImg);
    

    Mat image = imread("lena.jpg");
    std::vector<cv::Mat> channels;				//定义Mat型Vector变量
    cv::split(image, channels);					//调用split函数
    cv::Mat B = channels.at(0);
    cv::Mat G = channels.at(1);
    cv::Mat R = channels.at(2);
    namedWindow("channel blue", CV_WINDOW_NORMAL);
    imshow("channel blue", B);
    namedWindow("channel green", CV_WINDOW_NORMAL);
    imshow("channel green", G);
    namedWindow("channel red", 0);
    imshow("channel red", R);
    
    Mat B_jun, G_jun, R_jun;
    equalizeHist(B, B_jun);
    equalizeHist(G, G_jun);
    equalizeHist(R, R_jun);

    namedWindow("blue_equal", CV_WINDOW_NORMAL);
    imshow("blue_equal", B_jun);
    namedWindow("green_equal", CV_WINDOW_NORMAL);
    imshow("green_equal", G_jun);
    namedWindow("red_equal", CV_WINDOW_NORMAL);
    imshow("red_equal", R_jun);


    
    

    
    
    Mat img2 = imread("图片1.jpg", 0);
    Mat grayImg2;
    img2.convertTo(grayImg2, CV_64F, 1.0 / 255, 0);
    double gamma2 = 0.4;
    Mat gammaImg2;
    pow(grayImg2, gamma2, gammaImg2);
    gammaImg2.convertTo(gammaImg2, CV_8U, 255, 0);
    namedWindow("gammaImg2.jpg", CV_WINDOW_NORMAL);
    imshow("gammaImg2.jpg", gammaImg2);
    
    waitKey(0);
    
}   
