
#include <ASCIIGenerator.hpp>
#include <iostream>
#include <ASCIIStyle.hpp>
namespace ASCII
{
    #ifdef NDEBUG
        void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message) {
            printf("\n*** ");
            if(fif != FIF_UNKNOWN) {
                printf("%s Format\n", FreeImage_GetFormatFromFIF(fif));
            }
            printf("%s",message);
            printf(" ***\n");
        }
    #endif
    
    ImageASCIIGenerator::ImageASCIIGenerator(
        const char* IMAGE_FILE,
        const std::string_view& mapper,
        const float& ratio
        
    )
        :m_img(nullptr),
        format(FREE_IMAGE_FORMAT::FIF_UNKNOWN),
        ratio(
            std::max(ratio,0.1f)
        ),
        mapper(mapper)
    {
        //Check if path passed
        if(!IMAGE_FILE){return;}
        #ifdef NDEBUG
            std::printf("Image path: %s\n",IMAGE_FILE);
            FreeImage_SetOutputMessage(FreeImageErrorHandler);
        #endif
        //Get format of Image
        format = FreeImage_GetFileType(IMAGE_FILE);
        #ifdef NDEBUG
            std::printf("Image format: %d\n",format);
        #endif
        //Load image
        m_img = FreeImage_Load(format,IMAGE_FILE);
        if(!m_img){throw std::invalid_argument("Image is not Loaded");}
    }

    ImageASCIIGenerator::ImageASCIIGenerator(
        const char* IMAGE_FILE,
        ASCIIStyle& style,
        float const& ratio
    )
        :ImageASCIIGenerator(
            IMAGE_FILE,
            style.getStyleMapper(),
            ratio
        )
    {
    }

    ImageASCIIGenerator::~ImageASCIIGenerator(){
        FreeImage_Unload(m_img);
    }

    std::ostringstream&& ImageASCIIGenerator::GetArt(){

        constexpr int SECTION_HEIGTH = 20;
        constexpr int SECTION_WIDTH = 24;
        
        //Resize image by ratio cause symbols are vertical
        FIBITMAP * resized = FreeImage_Rescale(m_img,FreeImage_GetWidth(m_img),FreeImage_GetHeight(m_img)*ratio);
        
         //Convert image to grayscale version
        FIBITMAP *grayscaled_img = FreeImage_ConvertToGreyscale(resized);
        
        /*
            Map each pixel with corresponding character:
            1. split image into sections forming a grid(for instance, a section w =20,h=24)
            2. get the avarage grayscale value of each section
            2. map that value with corresponding ASCII value
        */

        const std::function<char(const int&)> mapToASCII = [this](const int& light)->char{
            const int& index =std::floor((light/255.0f) * (mapper.length()-1)) ;
            return mapper[index];
        };
        
        int avg =0;
        BYTE pixelIndex;
        //split into sections
        for (int h = 0; h < FreeImage_GetHeight(grayscaled_img); h+=SECTION_HEIGTH)
        {
            for (int w = 0; w < FreeImage_GetWidth(grayscaled_img); w+=SECTION_WIDTH)
            {
                for (int x = h; x < h+ SECTION_HEIGTH; x++)
                {
                    for (int y = w; y < w+SECTION_WIDTH; y++)
                    {
                        FreeImage_GetPixelIndex(grayscaled_img, y, x, &pixelIndex);
                        avg+=pixelIndex;
                    }
                }
                char symbol = mapToASCII(avg/(SECTION_HEIGTH* SECTION_WIDTH));
                m_sout << symbol;
                avg =0;
            }
            m_sout << "\n";
        }
        //Return Stream
        return std::move(m_sout);
    
    }

}