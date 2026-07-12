#pragma once 
#include <sstream>
#include <string_view>
#include <set>

#include <IASCIIGenerator.hpp>
#include <IImage.hpp>
#include <Image/IImageHandler.hpp>

namespace ASCII 
{
    
    class ImageASCIIGenerator:public IASCIIGenerator
    {
        protected:
            //stream for outputted ASCII image
            std::ostringstream m_sout;
            //image
            std::unique_ptr<IImage> m_imgAdapter;
            //Mapping symbols
            std::string_view m_mapper;
            //cell size;
            std::pair<unsigned int,unsigned int> m_cellSize;
            //Image Prepocessors;
            std::set<IImageHandler*> m_handlers;
        public:
            virtual std::ostringstream&& GetArt() override;
            /**
             * @param ratio: scaling factor of an Image for mapping and Image, the bigger the ration - more place to map
             */
            ImageASCIIGenerator(
                const std::string_view& mapper,
                IImage* imageAdapter,
                std::initializer_list<IImageHandler*> filters = std::initializer_list<IImageHandler*>(),
                const std::pair<unsigned int,unsigned int>& cellSize = std::make_pair(20,24)
            );
    };
}
