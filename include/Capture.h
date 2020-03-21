#ifndef CAPTURE_H_
#include <string>
#include <memory>

#include "Frame.h"

class Capture {
    public:
        Capture(std::string& path, unsigned int width, unsigned int height);
        void read(std::shared_ptr<Frame> frame);
        unsigned int width, height, size;
    private:
        std::string& _path;
};

#endif // CAPTURE_H_
