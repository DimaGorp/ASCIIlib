#pragma once

#include <sstream>
namespace ASCII
{
    class IASCIIGenerator{
    public:
        virtual std::ostringstream&& GetArt() = 0;
    };
}