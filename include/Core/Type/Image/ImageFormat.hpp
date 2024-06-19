#ifndef APALINEA_CORE_TYPE_IMAGEFORMAT_HPP
#define APALINEA_CORE_TYPE_IMAGEFORMAT_HPP

namespace Apalinea::Core::Type {
    enum class ImageFormat : int {
        FB_RGB888 = 0,
        FB_BGR888 = 1,
        FB_RGB565 = 2,
        FB_BGR565 = 3,
        FB_GRAY = 4
    };
} // Apalinea::Core::Type

#endif //APALINEA_CORE_TYPE_IMAGEFORMAT_HPP
