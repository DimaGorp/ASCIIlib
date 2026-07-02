#include <SFMLAdapter.hpp>
#include <SFML/Graphics.hpp>
std::vector<Pixel> SFMLAdapter::getImage()
{
    std::vector<Pixel> image;
    for (unsigned int i = 0; i < m_image.getSize().x; ++i)
    {
        for (unsigned int j = 0; j < m_image.getSize().y; ++j)
        {
            const sf::Color& pixel = m_image.getPixel({i,j});
            image.push_back(Pixel({pixel.r,pixel.g,pixel.b,pixel.a}));
        }
    }
    
    return image;
    
    
}
std::pair<short, short> SFMLAdapter::getImageSize()
{
    return std::make_pair(m_image.getSize().x, m_image.getSize().y);
}