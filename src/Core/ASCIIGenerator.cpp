
#include <ASCIIGenerator.hpp>
#include <iostream>
namespace ASCII
{
    ImageASCIIGenerator::ImageASCIIGenerator(
        std::function<ImageAdapter()> getImage,
        const std::string_view& mapper,
        const float& ratio,
        const std::pair<unsigned int,unsigned int>& CELL_SIZE
        
    ):
        m_ratio(
            std::max(ratio,0.1f)
        ),
        m_mapper(mapper),
        m_cellSize(CELL_SIZE)
    {
        //Get Image
        m_imgAdapter = getImage();
    }

    std::ostringstream&& ImageASCIIGenerator::GetArt(){
        ImageAdapter adapter;
        adapter.image_size = std::make_pair(m_imgAdapter.image_size.first, m_imgAdapter.image_size.second * m_ratio);
        
        
         //Convert image to grayscale version
        int* grayscaled_img;// = FreeImage_ConvertToGreyscale(resized);
        
        /*
            Map each pixel with corresponding character:
            1. split image into sections forming a grid(for instance, a section w =20,h=24)
            2. get the avarage grayscale value of each section
            2. map that value with corresponding ASCII value
        */

        const std::function<char(const int&)> &mapToASCII = [this](const int& light)->char{
            const int& index =std::floor((light/255.0f) * (m_mapper.length()-1)) ;
            return m_mapper[index];
        };
        
        int avg =0;
        //BYTE pixelIndex;
        /*
        //split into sections
        for (int h = 0; h < FreeImage_GetHeight(grayscaled_img); h+=m_cellSize.first)
        {
            for (int w = 0; w < FreeImage_GetWidth(grayscaled_img); w+=m_cellSize.second)
            {
                for (int x = h; x < h+ m_cellSize.first; x++)
                {
                    for (int y = w; y < w + m_cellSize.second; y++)
                    {
                        FreeImage_GetPixelIndex(grayscaled_img, y, x, &pixelIndex);
                        avg+=pixelIndex;
                    }
                }
                char symbol = mapToASCII(avg/(m_cellSize.first* m_cellSize.second));
                m_sout << symbol;
                avg =0;
            }
            m_sout << "\n";
        }
        */

        //Return Stream
        return std::move(m_sout);
    
    }

}
