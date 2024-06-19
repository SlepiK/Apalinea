#ifndef APALINEA_EXTRAS_CONVERTER_TYPES_PIXEL_RGBTOHSV_HPP
#define APALINEA_EXTRAS_CONVERTER_TYPES_PIXEL_RGBTOHSV_HPP

#include <algorithm>
#include "Core/Type/Pixel/RGB.hpp"
#include "Core/Type/Pixel/HSV.hpp"

namespace Apalinea::Extras::Converter::Types::Pixel {
    class RGBtoHSV {
    public:
        static void convert(const Core::Type::Pixel::RGB& rgb, Core::Type::Pixel::HSV& hsv) {
            float maxColor = (float)std::max(std::max(rgb.getR(), rgb.getG()), rgb.getB());
            float minColor = (float)std::min(std::min(rgb.getR(), rgb.getG()), rgb.getB());
            float delta = maxColor - minColor;

            hsv.setV(maxColor);

            if (maxColor != 0) {
                hsv.setS(delta / maxColor);
            } else {
                hsv.setS(0.f);
            }

            if (hsv.getS() == 0.f) {
                hsv.setH(0.f);
            } else {
                if ((float)rgb.getR() == maxColor) {
                    hsv.setH(((float)rgb.getG() - (float)rgb.getB()) / delta + ((float)rgb.getG() < (float)rgb.getB() ? 6.f : 0.f));
                } else if ((float)rgb.getG() == maxColor) {
                    hsv.setH(((float)rgb.getB() - (float)rgb.getR()) / delta + 2);
                } else if ((float)rgb.getB() == maxColor) {
                    hsv.setH(((float)rgb.getR() - (float)rgb.getG()) / delta + 4);
                }
                hsv.setH((hsv.getH() / 6.f) * 179.f);
            }
            hsv.setS(hsv.getS() * 255.f);
        }
    };
} // Apalinea::Extras::Converter::Types::Pixel

#endif //APALINEA_EXTRAS_CONVERTER_TYPES_PIXEL_RGBTOHSV_HPP
