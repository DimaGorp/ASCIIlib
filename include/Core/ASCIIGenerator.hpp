#pragma once 
#include <IASCIIGenerator.hpp>
#include <IImage.hpp>
#include <sstream>
#include <string_view>
#include <string>
#include <functional>
namespace ASCII 
{
    
    class ImageASCIIGenerator:public IASCIIGenerator
    {
        protected:
            //stream for outputted ASCII image
            std::ostringstream m_sout;
            //image
            std::unique_ptr<IImage> m_imgAdapter;
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
                IImage* imageAdapter,
                const std::string_view& mapper,
                float const& ratio = 0.5f,
                const std::pair<unsigned int,unsigned int>& cellSize = std::make_pair(20,24)
            );
    };
}
