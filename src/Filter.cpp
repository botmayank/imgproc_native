#include <algorithm>
#include "Filter.h"

Filter::Filter(unsigned int width, unsigned int height, FilterType filter):
    width(width), height(height), filter(filter) {
        size = width * height;
}

void Filter::process(std::shared_ptr<Frame> frame) {
    if(filter == FilterType::GRAY) {
        if(frame->getFormat() == PixelFormat::RGB){
            frame->toGraywithBrightness();
        }
    }
}

void Filter::increase_brightness(std::shared_ptr<Frame> frame) {
    frame->incrementOffset(0.5);
}

void Filter::decrease_brightness(std::shared_ptr<Frame> frame) {
    frame->decrementOffset(0.5);
}
