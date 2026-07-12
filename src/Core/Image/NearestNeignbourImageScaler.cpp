#include <Image/NearestNeignbourImageScaler.hpp>
#include <cmath>
namespace ASCII
{
    void NearestNeignbourImageScaler::apply(std::vector<Pixel>& image,std::pair<short, short>& image_size)
    {
        image_size.second *= m_ratio;
        std::vector<Pixel> interpolated(static_cast<size_t>(image_size.first * image_size.second));
        for (int y =0; y < image_size.second;++y)
        {
            for (int x = 0; x < image_size.first; ++x)
            {
                interpolated.at(x * image_size.second + y) = image.at(std::floor(y * image_size.first * m_ratio) + std::floor(x * m_ratio));
            }
        }
        image = interpolated;
    }
}
