#include <ASCIIStyle.hpp>

namespace ASCII{
    std::string_view ASCIIStyle::getStyleMapper(){
        switch (m_style)
        {
        case SOLID:
            return "";
        case SHADING:
            return "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";
        case LINE:
            return "/\"_-`|";
        }
    }
}