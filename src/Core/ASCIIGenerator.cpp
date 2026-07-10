
#include <ASCIIGenerator.hpp>
#include <iostream>
#include <functional>
#include <string>
namespace ASCII
{
    ImageASCIIGenerator::ImageASCIIGenerator(
        const std::string_view& mapper,
        IImage* imageAdapter,
        std::initializer_list<IImageHandler*> filters,
        const std::pair<unsigned int,unsigned int>& CELL_SIZE
    ):
        m_mapper(mapper),
        m_cellSize(CELL_SIZE)
    {
        //Initializing image adapter
        m_imgAdapter = std::unique_ptr<IImage>(imageAdapter);
        //Initialize image preprocessor handlers
        m_handlers = filters;
    }

    std::ostringstream&& ImageASCIIGenerator::GetArt(){
        //Get Image from Adapter
        std::vector<Pixel> pixels = m_imgAdapter->getImage();
        std::pair<short,short> image_size = m_imgAdapter->getImageSize();
        //check if any filters was applied
        if (!m_handlers.empty())
        {
            for (auto& handler : m_handlers)
            {
                handler->apply(pixels, image_size);
            }
        }
        
        /*
            Map each pixel with corresponding character:
            1. split image into sections forming a grid(for instance, a section w =20,h=24)
            2. get the average grayscale value of each section
            2. map that value with corresponding ASCII value
        */

        const std::function<char(const int&)> &mapToASCII = [this](const int& light)->char{
            const int& index =std::floor((light/255.0f) * (m_mapper.length() - 1)) ;
            return m_mapper[index];
        };
        
        int avg =0;
        int pixelIndex;
        
        //split into sections
        for (unsigned short h = 0; h < image_size.second; h+=m_cellSize.first)
        {
            for (unsigned short w = 0; w < image_size.first; w+=m_cellSize.second)
            {
                for (unsigned int x = h; x < h+ m_cellSize.first; x++)
                {
                    for (unsigned int y = w; y < w + m_cellSize.second; y++)
                    {
                        //FreeImage_GetPixelIndex(grayscaled_img, y, x, &pixelIndex);
                        //avg+=pixelIndex;
                    }
                }
                char symbol = mapToASCII(avg/(m_cellSize.first* m_cellSize.second));
                m_sout << symbol;
                avg =0;
            }
            m_sout << "\n";
        }
        

        //Return Stream
        return std::move(m_sout);
    
    }

}
