#include <iostream>
#include <Config.h>
#include <Core/ASCIIGenerator.hpp>
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
            printf("Successfully loaded image \"image.png\"\n \tImage\\ \n\t\tSize: %dX%d\n",image.getSize().x, image.getSize().y);
            
            ASCII::ImageAdapter adapter;
            adapter.image_size = std::make_pair(image.getSize().x, image.getSize().y);
            for (int i =0; i<image.getSize().y; i++) {
                for (int j =0; j<image.getSize().x; j++) {
                    adapter.image.push_back(
                                            {
                                                image.getPixel(sf::Vector2u(i,j)).r,
                                                image.getPixel(sf::Vector2u(i,j)).g,
                                                image.getPixel(sf::Vector2u(i,j)).b
                                            }
                                            );
                }
            }
            ASCII::ImageASCIIGenerator([&image]{
            }, "+- ");
            
        }catch(const std::exception& e){
            std::cout<<e.what()<<"\n";
        }
    #else
        std::cout << "SFML NOT FOUND" << std::endl; 
    #endif
    return 0;
}
