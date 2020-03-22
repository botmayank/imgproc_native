#include "Filter.h"

Filter::Filter(unsigned int width, unsigned int height, FilterType filter):
    width(width), height(height), filter(filter) {
        size = width * height;
}

void Filter::process(std::shared_ptr<Frame> frame) {
    cv::Mat frameMat = frame->toMat();
    
    if(filter == FilterType::GRAY) {
        cvtColor(frameMat, frameMat, CV_BGR2GRAY);
        frame->pixelFormat = PixelFormat::GRAY;
    }
    frame->setData(frameMat);
}
