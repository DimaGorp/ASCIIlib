#include <iostream>
#include <Config.h>
#include <Core/ASCIIGenerator.hpp>
int main(int argc, const char * argv[]) {
    
    try{
       /*ASCII::ImageASCIIGenerator ASCII(
            "+- ",
            0.5f,
            std::make_pair(25,28));
        std::ostringstream out = ASCII.GetArt();
        std::cout << out.str();*/
    }catch(std::invalid_argument& ex){
        std::printf("%s\n",ex.what());
    }
    return 0;
}