#ifndef FILTER_H_
#define FILTER_H_

#include <memory>
#include "Frame.h"

enum class FilterType {
    GRAY
};

class Filter {
    public:
        Filter(unsigned int width, unsigned int height, FilterType filter = FilterType::GRAY);
        void process(std::shared_ptr<Frame> frame);
        unsigned int width, height, size;
        FilterType filter;

};

#endif //FILTER_H_
