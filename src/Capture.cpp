#include "Capture.h"

Capture::Capture(std::string& path): _path(path) {
    std::cout << "Initializing Capture" << std::endl;
}

void Capture::read(std::shared_ptr<Frame> frame) {
    for(int i = 0; i < frame->size; ++i) {
        frame->data.push_back(127);
    }
}
