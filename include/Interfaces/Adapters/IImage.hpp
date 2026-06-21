#pragma once
#include <vector>
struct Pixel
{
    unsigned short r{0},g{0},b{0},a{0};
};

//Image Interface for converting 3d-party Image Libs to Core representation of Image
class IImage
{
    public:
        virtual std::vector<Pixel> getImage() = 0;
        virtual std::pair<short, short> getImageSize() = 0;
};