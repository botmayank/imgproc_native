#ifndef KEYBOARD_LED_H_
#define KEYBOARD_LED_H_
#include <thread>

class KeyboardLed {
    public:
        KeyboardLed(unsigned int blinkDelay);
        void run();
        void stop();

    private:
        void blinkLed();
        void setLed(bool enable);

        std::unique_ptr<std::thread> ledThread;
        unsigned int blinkDelay;
        bool keepRunning;
        std::string path;
};

#endif //KEYBOARD_LED_H_
