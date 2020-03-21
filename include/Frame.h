#ifndef FRAME_H_
#define FRAME_H_

#include <iostream>
#include <vector>

class Frame{
    public:
        Frame(unsigned int width, unsigned int height);
        std::vector<uint8_t> data;
        unsigned int width, height, size;
};

#endif // FRAME_H_