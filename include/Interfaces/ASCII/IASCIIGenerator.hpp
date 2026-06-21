#pragma once

#include <sstream>
class IASCIIGenerator{
    public:
        virtual std::ostringstream&& GetArt() = 0;
};