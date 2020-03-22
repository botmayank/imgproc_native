#ifndef CAPTURE_H_
#define CAPTURE_H_

#include <string>
#include <memory>
#include <thread>

#include "Frame.h"

class Capture {
    public:
        Capture(std::string& path, unsigned int width, unsigned int height);
        void read(std::shared_ptr<Frame> frame);
        void run(std::shared_ptr<Frame> frame);
        void stop();

        unsigned int width, height, size;
    private:
        std::string& _path;
        std::unique_ptr<cv::VideoCapture> cap;
        std::unique_ptr<std::thread> captureThread;
        bool keepRunning;
};

#endif // CAPTURE_H_
