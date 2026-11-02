#pragma once
#include <IImage.hpp>
namespace ASCII
{
    class IImageHandler
    {
        public:
            virtual void apply(std::vector<Pixel>& image,std::pair<short, short>& image_size) = 0;
    };
}