/* 
    Image processing scratchpad
    Mayank Joneja
*/

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Capture.h"

int main() {
    unsigned int width = 640, height = 480;
    std::cout << "Let's mess around with images!" << std::endl;
    std::string capture_path = "/dev/video0";
    Capture cap(capture_path, width, height);

    std::shared_ptr<Frame> inputFrame = std::make_shared<Frame> (width, height);

    while (1) {
        cap.read(inputFrame);

        std::cout << "Frame data: [";
        for (unsigned int i = 0; i < 10; ++i) {
            std::cout << static_cast<int>(inputFrame->data[i]) << " ";
        }
        std::cout << "] " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
