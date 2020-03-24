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

void Frame::toGraywithBrightness() {
    cv::Mat frameMat = this->toMat();
    cvtColor(frameMat, frameMat, CV_BGR2GRAY);
    setData(frameMat, PixelFormat::GRAY);
    {
        std::lock_guard<std::mutex> guard(frameMutex);
        for(auto i = data.begin(); i != data.end(); i++) {
            unsigned int pix = static_cast<unsigned int>(static_cast<float>(*i) + brightness);
            *i = clamp<uint8_t>(pix, 0, 255);
        }
    }
}

void Frame::incrementOffset(float offset) {
    std::lock_guard<std::mutex> guard(frameMutex);
    brightness = clamp<float>(brightness + offset, minBrightness, maxBrightness );
    std::cerr << "Increased brightness to: " << static_cast<float>(brightness) << std::endl;
}

void Frame::decrementOffset(float offset) {
    std::lock_guard<std::mutex> guard(frameMutex);
    brightness = clamp<float>(brightness - offset, minBrightness, maxBrightness);
    std::cerr << "Decreased brightness to: " << static_cast<float>(brightness) << std::endl;
}
