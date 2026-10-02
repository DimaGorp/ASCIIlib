#include <Image/ImageGrayscaler.hpp>

namespace ASCII
{
    void ImageGrayscaler::apply(std::vector<Pixel>& image,std::pair<short, short>& image_size)
    {
        int grayscale;
        for (auto& pixel : image)
        {
            grayscale= int(0.299*pixel.r + 0.587*pixel.g + 0.114*pixel.b);
            pixel.r=static_cast<unsigned short>(grayscale);
            pixel.g=static_cast<unsigned short>(grayscale);
            pixel.b=static_cast<unsigned short>(grayscale);
        }
    }
}
