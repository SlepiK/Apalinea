//
// Created by SlepiK on 29.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_IMAGEFORMAT_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_IMAGEFORMAT_HPP

namespace Energyleaf::Stream::V1::Types {

    enum class ImageFormat : int {
        FB_RGB888 = 0,
        FB_BGR888 = 1,
        FB_RGB565 = 2,
        FB_BGR565 = 3,
        FB_GRAY = 4
    };
} // Energyleaf::Stream::V1::Types

#endif //ENERGYLEAF_STREAM_V1_TYPES_IMAGEFORMAT_HPP
