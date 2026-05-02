#include <iostream>
#include <Config.h>
#ifdef SFML_FOUND
    #include <SFML/Graphics.hpp>
#endif
int main()
{
    #ifdef SFML_FOUND
        try{
            sf::Image image;
            if(!image.loadFromFile(std::string(RESOURCES_DIR)+"/image.png")){
                throw "Failed to load image \"image.png\" \n";
            }
            printf("Successfully loaded image \"image.png\"\n \tImage\\ \n\t\tSize: %dX%d",image.getSize().x, image.getSize().y);
            //TODO: show algorithm usage
        }catch(const std::exception& e){
            std::cout<<e.what()<<"\n";
        }
    #else
        std::cout << "SFML NOT FOUND" << std::endl; 
    #endif
    return 0;
}