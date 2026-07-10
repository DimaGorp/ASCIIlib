#include <Image/ImageGrayscaler.hpp>

namespace ASCII
{
    void ImageGrayscaler::apply(std::vector<Pixel>& image,std::pair<short, short>& image_size)
    {
        int grayscale;
        for (auto& pixel : image)
        {
            grayscale= (pixel.r+pixel.g+pixel.b)/3;
            pixel.r=static_cast<unsigned short>(grayscale);
            pixel.g=static_cast<unsigned short>(grayscale);
            pixel.b=static_cast<unsigned short>(grayscale);
        }
    }
}
