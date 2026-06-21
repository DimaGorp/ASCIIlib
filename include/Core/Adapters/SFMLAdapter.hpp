#pragma once
#include <SFML/Graphics.hpp>
#include <Interfaces/IImage>

class SFMLAdapter: public IImageAdapter
{
    protected:
        sf::Image& m_image;
    public:
        SFMLAdapter(sf::Image& image):m_image(image){};
        virtual std::vector<Pixel>
    
};