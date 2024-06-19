//
// Created by SlepiK on 01.02.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ABSTRACTCAMERA_HPP
#define ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ABSTRACTCAMERA_HPP

#include <stdexcept>
#include "Core/Type/Image/Image.hpp"

namespace Apalinea::Extras::Vision {
    template<typename Config>
    class AbstractCamera {
    public:
        AbstractCamera() : vStarted(false) {
        };

        virtual ~AbstractCamera() = default;

        virtual void start() final {
            if (this->vStarted) {
                throw std::runtime_error("AbstractCamera is already started!");
            }

            this->internalStart();

            this->vStarted = true;
        };

        virtual void stop() final {
            if (!this->vStarted) {
                throw std::runtime_error("AbstractCamera is not started!");
            }

            this->internalStop();

            this->vStarted = false;
        }

        [[nodiscard]] virtual bool isStarted() const final{
            return this->vStarted;
        }

        [[nodiscard]] virtual Core::Types::Image getImage() const final{
            if (!this->vStarted) {
                throw std::runtime_error("AbstractCamera is not started!");
            }

            return this->getInternalImage();
        }

        virtual const Config& getConfig() const = 0;

        virtual void setConfig(Config&& config) = 0;

        virtual void setConfig(Config& config) = 0;

    private:
    protected:
        bool vStarted;
        virtual void internalStart() = 0;
        virtual void internalStop() = 0;
        [[nodiscard]] virtual Core::Types::Image getInternalImage() const = 0;
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXPTRAS_VISION_ABSTRACTCAMERA_HPP
