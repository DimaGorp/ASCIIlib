#include <iostream>
#include <Config.h>
#include <Core/ASCIIGenerator.hpp>
#include <Adapters/SFMLAdapter.hpp>
#ifdef SFML
    #include <SFML/Graphics.hpp>
#endif
int main()
{
    #ifdef SFML
        try{
            sf::Image image;
            if(!image.loadFromFile(std::string(RESOURCES_DIR)+"/image.png")){
                throw "Failed to load image \"image.png\" \n";
            }
            printf("Successfully loaded image \"image.png\"\n \tImage\\ \n\t\tSize: %dX%d\n",image.getSize().x, image.getSize().y);
           
            ASCII::ImageASCIIGenerator generator([&image]->std::unique_ptr<IImage>{
                return std::make_unique<SFMLAdapter>(image);
            }, "+- ");
            generator.GetArt();
        }catch(const std::exception& e){
            std::cout<<e.what()<<"\n";
        }
    #else
        std::cout << "SFML NOT AVALIABLE" << std::endl; 
    #endif
    return 0;
}
