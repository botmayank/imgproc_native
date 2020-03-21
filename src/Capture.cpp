#include "Capture.h"

Capture::Capture(std::string& path, unsigned int width, unsigned int height):
                width(width), height(height), _path(path) {
    std::cout << "Initializing Capture" << std::endl;
    size = width * height;
}

void Capture::read(std::shared_ptr<Frame> frame) {
    for (unsigned int i = 0; i < frame->size; ++i) {
        frame->data.push_back(127);
    }
}
