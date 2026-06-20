#pragma once 
#include <ASCII/IASCIIGenerator.hpp>
#include <sstream>
#include <string_view>
#include <string>
namespace ASCII 
{

    struct ImageAdapter{
        struct Pixel{
            unsigned short r{0},g{0},b{0};
        };
        std::vector<Pixel> image;
        std::pair<unsigned short,unsigned short> image_size;
    };
    class ImageASCIIGenerator:public IASCIIGenerator
    {
        protected:
            //stream for outputted ASCII image
            std::ostringstream m_sout;
            //image
            ImageAdapter m_imgAdapter;
            //ratio
            float m_ratio;
            //Mapping symbols
            std::string_view m_mapper;
            //cell size;
            std::pair<unsigned int,unsigned int> m_cellSize;
            
        public:
            virtual std::ostringstream&& GetArt() override;
            /**
             * @param ratio: scaling factor of an Image for mapping and Image, the bigger the ration - more place to map
             */
            ImageASCIIGenerator(
                std::function<ImageAdapter()> getImage,
                const std::string_view& mapper,
                float const& ratio = 0.5f,
                const std::pair<unsigned int,unsigned int>& cellSize = std::make_pair(20,24)
            );
    };
}
