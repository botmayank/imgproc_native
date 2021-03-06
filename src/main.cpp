/* 
    Image processing scratchpad
    Mayank Joneja
*/

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <exception>
#include <opencv2/opencv.hpp>

#include "Capture.h"
#include "Display.h"
#include "Filter.h"
#include "KeyboardLed.h"

#define KEY_ESC     27
#define KEY_o       111
#define KEY_k       107

int main(int argc, char** argv) {
    std::cout << "Let's mess around with images!" << std::endl;
    bool useFilter = false;

    if (argc == 2) {
        std::string arg = argv[1];
        if (arg == "gray")
            useFilter = true;
    }
    std::cout << "Launching with filter set to: " << static_cast<int>(useFilter) << std::endl;

    unsigned int width = 640, height = 480;
    std::string capturePath = "/dev/video0";
    std::string dispWindow = "Basic output";

    Capture cap(capturePath, width, height);
    Display disp(dispWindow, width, height);
    Filter filter(width, height);

    std::shared_ptr<Frame> inputFrame = std::make_shared<Frame> (width, height);
    unsigned int frameCount = 0;

    cap.run(inputFrame); // start capture in separate thread

    KeyboardLed led(1); // blink delay in seconds
    led.run();          // blink keyboard backlight in separate thread

    while (1) {
        try{
            // std::cout << "Reading frame num: " << frameCount <<  std::endl;
            if(useFilter)
                filter.process(inputFrame);
            disp.show(inputFrame);

            frameCount++;

            char key = cv::waitKey(1);
            if (key == KEY_ESC) {
                std::cerr << "Exiting..." << std::endl;
                break;
            } else if(key == KEY_o) {
                // std::cerr << "Increase brightness" << std::endl;
                filter.increase_brightness(inputFrame);
            } else if(key == KEY_k){
                // std::cerr << "Decrease brightness" << std::endl;
                filter.decrease_brightness(inputFrame);
            }
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            break;
        }
    }
    cap.stop();
    led.stop();
    return 0;
}
