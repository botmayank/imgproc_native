#ifndef CAPTURE_H_
#include <string>
#include <memory>

#include "Frame.h"

class Capture {
    public:
        Capture(std::string& path);
        void read(std::shared_ptr<Frame> frame);

    private:
        std::string& _path;
};

#endif // CAPTURE_H_
