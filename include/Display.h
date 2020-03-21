#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include <memory>
#include <opencv2/opencv.hpp>

#include "Frame.h"

class Display {
    public:
        Display(std::string& windowName, unsigned int width, unsigned int height);
        unsigned int width, height;
        void show(std::shared_ptr<Frame> frame);

    private:
        std::string _windowName;
};

#endif // DISPLAY_H_