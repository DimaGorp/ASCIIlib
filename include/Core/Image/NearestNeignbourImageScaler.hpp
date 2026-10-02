#include <Image/IImageHandler.hpp>
#include <algorithm>
namespace ASCII
{
    class NearestNeignbourImageScaler: public IImageHandler
    {
        protected:
            std::pair<short,short> m_img_size;
        public:
            NearestNeignbourImageScaler(std::pair<short,short> newImgSize = std::make_pair<short,short>(16,16))
            {
                m_img_size = std::max(newImgSize, {1,1});
            };
            virtual void apply(std::vector<Pixel>& image,std::pair<short, short>& image_size) override;
    };
}