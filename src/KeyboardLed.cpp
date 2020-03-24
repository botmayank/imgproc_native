#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#include "KeyboardLed.h"

void blinkLed(unsigned int times) {
    for(unsigned int i = 0 ; i < times; i++) {
        setLed(true);
        std::cerr << "Keyboard backlight: on" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        setLed(false);
        std::cerr << "Keyboard backlight: off" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void setLed(bool enable) {
    std::string path = "/sys/class/leds/asus::kbd_backlight/brightness";

    std::ofstream keyboardFile(path);
    if(!keyboardFile) {
        std::cerr << "Can't access keyboard backlight, re-run with sudo!" << std::endl;
    }
    if(enable) {
        keyboardFile << 3;
    } else {
        keyboardFile << 0;
    }
    keyboardFile.close();
}
