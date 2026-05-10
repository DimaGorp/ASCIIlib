#pragma once 
#include <FreeImage.h>
#include <ASCII/IASCIIGenerator.hpp>
#include <sstream>
#include <string_view>
#include <string>
namespace ASCII 
{
    class ASCIIStyle;
    class ImageASCIIGenerator:public IASCIIGenerator
    {
        protected:
            //stream for outputted ASCII image
            std::ostringstream m_sout;
            //Image
            FIBITMAP* m_img;
            //Image format
            FREE_IMAGE_FORMAT format;
            //scale ratio of Image
            float ratio;
            //Mapping symbols
            std::string_view mapper;
        public:

            virtual std::ostringstream&& GetArt() override;

            ImageASCIIGenerator() = delete;
            /**
             * @param IMAGE_FILE: absolute or relative path to which image is located
             * @param ratio: scaling factor of an Image for mapping and Image, the bigger the ration - more place to map
             */
            ImageASCIIGenerator(
                const char* IMAGE_FILE,
                const std::string_view& mapper,
                float const& ratio =0.5f
            );
            ImageASCIIGenerator(
                const char* IMAGE_FILE,
                ASCIIStyle& style,
                float const& ratio =0.5f
            );

            //destructor
            ~ImageASCIIGenerator();
    };
}
