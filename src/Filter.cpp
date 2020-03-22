#include "Filter.h"

Filter::Filter(unsigned int width, unsigned int height, FilterType filter):
    width(width), height(height), filter(filter) {
        size = width * height;
}

void Filter::process(std::shared_ptr<Frame> frame) {
    cv::Mat frameMat = frame->toMat();
    // std::cout << "Frame format before conversion to gray: " <<
    //                 (int) frame->getFormat() << std::endl;
    
    if(filter == FilterType::GRAY) {
        if(frame->getFormat() == PixelFormat::RGB){
            cvtColor(frameMat, frameMat, CV_BGR2GRAY);
            frame->setFormat(PixelFormat::GRAY);
        }
    }
    frame->setData(frameMat);
}
