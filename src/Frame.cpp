#include "Frame.h"

Frame::Frame(unsigned int width, unsigned int height, PixelFormat pixelFormat):
            width(width), height(height), pixelFormat(pixelFormat) {
    size = width * height * 3; // assume RGB
    data.reserve(size);
    data.assign(data.size(), 0);
}
