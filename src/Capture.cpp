#include "Capture.h"

Capture::Capture(std::string& path, unsigned int width, unsigned int height):
                width(width), height(height), _path(path) {
    std::cout << "Initializing Capture: " << width << "x" << height << std::endl;
    size = width * height;

    cap = std::make_unique<cv::VideoCapture>(_path);
    
    if (!cap->isOpened()) {
        std::cerr << "Failed to open path: " << _path << std::endl;
    }
}

void Capture::read(std::shared_ptr<Frame> frame) {
    for (unsigned int i = 0; i < frame->size; ++i) {
        frame->data.push_back(127);
    }
}
