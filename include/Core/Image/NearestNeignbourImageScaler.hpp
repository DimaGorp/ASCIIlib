#include <Image/IImageHandler.hpp>
#include <algorithm>
namespace ASCII
{
    class NearestNeignbourImageScaler: public IImageHandler
    {
        protected:
            float m_ratio;
        public:
            NearestNeignbourImageScaler(float ratio = 0.5f)
            {
                m_ratio = std::max(ratio,0.1f);
            };
            virtual void apply(std::vector<Pixel>& image,std::pair<short, short>& image_size) override;
    };
}