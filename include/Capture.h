#ifndef CAPTURE_H_
#define CAPTURE_H_

#include <string>
#include <memory>
#include <opencv2/opencv.hpp>

#include "Frame.h"

class Capture {
    public:
        Capture(std::string& path, unsigned int width, unsigned int height);
        ~Capture();
        void read(std::shared_ptr<Frame> frame);
        unsigned int width, height, size;

    private:
        std::string& _path;
        cv::VideoCapture *cap;
};

#endif // CAPTURE_H_
