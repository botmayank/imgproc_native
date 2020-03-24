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

/* Utility function from C++17 */
template<class T>
constexpr const T& clamp( const T& v, const T& lo, const T& hi )
{
    assert( !(hi < lo) );
    return (v < lo) ? lo : (hi < v) ? hi : v;
}

class Frame{
    public:
        Frame(unsigned int width, unsigned int height, PixelFormat pixelFormat = PixelFormat::RGB);
        void setData(cv::Mat frameMat, PixelFormat format);
        void setFormat(PixelFormat format);
        PixelFormat getFormat() { return pixelFormat; };
        void incrementOffset(float offset);
        void decrementOffset(float offset);
        cv::Mat toMat();
        void toGraywithBrightness();

        unsigned int width, height, size;
    private:
        std::mutex frameMutex;
        PixelFormat pixelFormat;
        std::vector<uint8_t> data;
        float brightness = 0.0, minBrightness = -0.5, maxBrightness = +24.5;
};

#endif // FRAME_H_
