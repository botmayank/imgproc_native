#include "Frame.h"

Frame::Frame(unsigned int width, unsigned int height):
            width(width), height(height) {
    size = width * height;
    data.reserve(size);
}
