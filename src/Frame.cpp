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
    } else if (pixelFormat == PixelFormat::GRAY) {
        cv::Mat frameMat(height, width, CV_8UC1, data.data());
        return frameMat;
    }
    else {
        std::cerr << "Unsupported format!" << std::endl;
        cv::Mat empty;
        return empty;
    }
}

void Frame::setData(cv::Mat frameMat, PixelFormat format) {
    cv::Mat flatMat = frameMat.reshape(1, frameMat.total()*frameMat.channels());
    std::lock_guard<std::mutex> guard(frameMutex);
    data = frameMat.isContinuous()? flatMat : flatMat.clone();
    pixelFormat = format;
}

void Frame::setFormat(PixelFormat format) {
    std::lock_guard<std::mutex> guard(frameMutex);
    pixelFormat = format;
}