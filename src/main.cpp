/* 
    Image processing scratchpad
    Mayank Joneja
*/

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <opencv2/opencv.hpp>

#include "Capture.h"
#include "Display.h"

#define KEY_ESC     27

int main() {
    std::cout << "Let's mess around with images!" << std::endl;

    unsigned int width = 640, height = 480;
    std::string capturePath = "/dev/video0";
    std::string dispWindow = "Basic output";

    Capture cap(capturePath, width, height);
    Display disp(dispWindow, width, height);
    std::shared_ptr<Frame> inputFrame = std::make_shared<Frame> (width, height);

    while (1) {
        cap.read(inputFrame);
        disp.show(inputFrame);

        char key = cv::waitKey(1);
        if (key == KEY_ESC) {
            std::cerr << "Exiting..." << std::endl;
            break;
        }
    }

    return 0;
}
