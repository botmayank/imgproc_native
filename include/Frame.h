#ifndef FRAME_H_
#define FRAME_H_

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <opencv2/opencv.hpp>

enum class PixelFormat {
    GRAY,       // w * h
    RGB,        // w * h * 3
    YUV422,     // w * h * 2
    YUV420      // w * h * 3/2
};

class Frame{
    public:
        Frame(unsigned int width, unsigned int height, PixelFormat pixelFormat = PixelFormat::RGB);
        void setData(cv::Mat frameMat);
        void setFormat(PixelFormat format);
        PixelFormat getFormat() { return pixelFormat; };
        void toGray();
        cv::Mat toMat();

        unsigned int width, height, size;
    private:
        std::mutex frameMutex;
        PixelFormat pixelFormat;
        std::vector<uint8_t> data;
};

#endif // FRAME_H_
