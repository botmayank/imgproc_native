#include "Display.h"

Display::Display(std::string& windowName, unsigned int width, unsigned int height):
                width(width), height(height), _windowName(windowName) {
    cv::namedWindow(_windowName);
}

void Display::show(std::shared_ptr<Frame> frame) {
    cv::Mat frameMat(frame->height, frame->width, CV_8U, frame->data.data());
    cv::imshow(_windowName, frameMat);
}
