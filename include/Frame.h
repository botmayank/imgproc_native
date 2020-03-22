#ifndef FRAME_H_
#define FRAME_H_

#include <iostream>
#include <vector>
#include <memory>

enum class PixelFormat {
    RGB,        // w * h * 3
    YUV422,     // w * h * 2
    YUV420      // w * h * 3/2
};

class Frame{
    public:
        Frame(unsigned int width, unsigned int height, PixelFormat pixelFormat = PixelFormat::RGB);
        cv::Mat toMat();

        std::vector<uint8_t> data;
        unsigned int width, height, size;
        PixelFormat pixelFormat;
};

#endif // FRAME_H_
