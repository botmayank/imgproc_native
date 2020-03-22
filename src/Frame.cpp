#include <opencv2/opencv.hpp>
#include "Frame.h"

Frame::Frame(unsigned int width, unsigned int height, PixelFormat pixelFormat):
            width(width), height(height), pixelFormat(pixelFormat) {
    size = width * height * 3; // assume RGB
    data.reserve(size);
    data.assign(data.size(), 0);
}

cv::Mat Frame::toMat() {
    if(pixelFormat == PixelFormat::RGB) {
        cv::Mat frameMat(height, width, CV_8UC3, data.data());
        return frameMat;
    }
    else {
        std::cerr << "Unsupported format!" << std::endl;
        cv::Mat empty;
        return empty;
    }
}
