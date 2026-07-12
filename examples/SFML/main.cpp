#include <iostream>
#include <Config.h>
#include <Core/ASCIIGenerator.hpp>
#include <Adapters/SFMLAdapter.hpp>
#include <Core/Image/ImageGrayscaler.hpp>
#include <Core/Image/NearestNeignbourImageScaler.hpp>
#ifdef SFML
    #include <SFML/Graphics.hpp>
#endif
int main()
{
    #ifdef SFML
        try{
            sf::Image image;
            if(!image.loadFromFile(std::string(RESOURCES_DIR)+"/camera.png")){
                throw "Failed to load image \"2.jpg\" \n";
            }
            printf("Successfully loaded image \"2.jpg\"\n \tImage\\ \n\t\tSize: %dX%d\n",image.getSize().x, image.getSize().y);
            ASCII::ImageASCIIGenerator generator("+- ",new SFMLAdapter(image),
                {
                    new ASCII::ImageGrayscaler(),
                    new ASCII::NearestNeignbourImageScaler(0.5)
                    }
                        );
            std::ostringstream out = generator.GetArt();
            std::cout << out.str();
        }catch(const std::exception& e){
            std::cout<<e.what()<<"\n";
        }
    #else
        std::cout << "SFML NOT AVALIABLE" << std::endl; 
    #endif
    return 0;
}
