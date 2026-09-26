#include <Image/NearestNeignbourImageScaler.hpp>
#include <cmath>
namespace ASCII
{
    void NearestNeignbourImageScaler::apply(std::vector<Pixel>& image,std::pair<short, short>& image_size)
    {
        //Define ratio for height and width 
        float ratio_w,ratio_h;
        ratio_w= static_cast<float>(image_size.first)/static_cast<float>(m_img_size.first);
        ratio_h= static_cast<float>(image_size.second)/static_cast<float>(m_img_size.second);
        //Create new image;
        std::vector<Pixel> interpolated(m_img_size.first * m_img_size.second);
        
        for (int y =0; y < m_img_size.second;++y)
        {
            for (int x = 0; x < m_img_size.first; ++x)
            {
                int in_y = std::min(static_cast<int>(std::floor(y*ratio_h)),image_size.second-1);
                int in_x = std::min(static_cast<int>(std::floor(x*ratio_w)),image_size.first-1);
                interpolated.at(y * m_img_size.first + x) = image.at(in_y * image_size.first + in_x);
            }
        }
        image_size = m_img_size;
        image = interpolated;
    }
}
