#pragma once
#include <Image/IImageHandler.hpp>

namespace ASCII
{
    class ImageGrayscaler: public IImageHandler
    {
        public:
            virtual void apply(std::vector<Pixel>& image,std::pair<short, short>& image_size) override;
    };
}