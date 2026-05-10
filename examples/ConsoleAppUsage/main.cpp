#include <iostream>
#include <Config.h>
#include <Core/ASCIIGenerator.hpp>
#include <Core/Styles/ASCIIStyle.hpp>
int main(int argc, const char * argv[]) {
    
    try{
        ASCII::ASCIIStyle style =ASCII::ASCIIStyle(ASCII::ASCIIStyle::SHADING);
        ASCII::ImageASCIIGenerator ASCII(
            std::string(RESOURCES_DIR+ std::string("/3.jpg")).c_str()
            ,style);
        std::ostringstream out = ASCII.GetArt();
        std::cout << out.str();
    }catch(std::invalid_argument& ex){
        std::printf("%s\n",ex.what());
    }
    return 0;
}