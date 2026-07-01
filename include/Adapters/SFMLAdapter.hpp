#pragma once
#include <Interfaces/Adapters/IImage.hpp>


namespace sf
{
    class Image;
};

class SFMLAdapter: public IImage
{
    protected:
        sf::Image& m_image;
    public:
        SFMLAdapter(sf::Image& image):m_image(image){};
        virtual std::vector<Pixel> getImage() override;
        virtual std::pair<short, short> getImageSize() override;
    
};