//
// Created by SlepiK on 02.02.2024.
//

#ifndef ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ICAMERA_HPP
#define ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ICAMERA_HPP

#include "Types/Image/Image.hpp"

namespace Energyleaf::Stream::V1::Extras::Vision {
    class ICamera {
    public:
        ICamera() = default;

        virtual ~ICamera() = default;

        virtual void start() = 0;

        virtual void stop() = 0;

        [[nodiscard]] virtual bool isStarted() const  = 0;

        virtual Energyleaf::Stream::V1::Types::Image getImage()  = 0;
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ICAMERA_HPP
