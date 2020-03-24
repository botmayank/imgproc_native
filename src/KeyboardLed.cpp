#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#include "KeyboardLed.h"

KeyboardLed::KeyboardLed(unsigned int blinkDelay): blinkDelay(blinkDelay), keepRunning(false) {
    path = "/sys/class/leds/asus::kbd_backlight/brightness";
}

void KeyboardLed::blinkLed() {
    while(keepRunning){
        setLed(true);
        // std::cerr << "Keyboard backlight: on" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(blinkDelay * 1000));

        setLed(false);
        // std::cerr << "Keyboard backlight: off" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(blinkDelay * 1000));
    }
}

void KeyboardLed::setLed(bool enable) {
    std::ofstream keyboardFile(path);
    if(!keyboardFile) {
        std::cerr << "Can't access keyboard backlight, re-run with sudo!" << std::endl;
    }
    if(enable) {
        keyboardFile << 3; // Max brightness
    } else {
        keyboardFile << 0;
    }
    keyboardFile.close();
}

void KeyboardLed::run() {
    ledThread = std::make_unique<std::thread>(&KeyboardLed::blinkLed, this);
    keepRunning = true;
}

void KeyboardLed::stop() {
    keepRunning = false;
    ledThread->join();
}
