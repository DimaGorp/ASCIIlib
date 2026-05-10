#pragma once
#include <string_view>
namespace ASCII{
    class ASCIIStyle{
        public:
            enum Style{
                SOLID,
                SHADING,
                LINE
            };
        
            std::string_view getStyleMapper();

            ASCIIStyle():m_style(Style::SOLID){}
            ASCIIStyle(const Style& style):m_style(style){};
        private:
            Style m_style;
    };
}