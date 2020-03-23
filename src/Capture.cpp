#include "Capture.h"

Capture::Capture(std::string& path, unsigned int width, unsigned int height):
                width(width), height(height), _path(path) {
    std::cout << "Initializing Capture: " << width << "x" << height << std::endl;
    size = width * height;

    cap = std::make_unique<cv::VideoCapture>(_path);

    if (!cap->isOpened()) {
        std::cerr << "Failed to open path: " << _path << std::endl;
    }
    keepRunning = false;
}

void Capture::read(std::shared_ptr<Frame> frame) {
    while(keepRunning){
        cv::Mat frameMat;
        cap->read(frameMat);
        frame->setData(frameMat, PixelFormat::RGB);
    }
}

void Capture::run(std::shared_ptr<Frame> frame) {
    keepRunning = true;
    captureThread = std::make_unique<std::thread>(&Capture::read, this, frame);
}

void Capture::stop() {
    keepRunning = false;
    captureThread->join();
}
