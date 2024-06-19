#ifndef APALINEA_EXTRAS_VISION_ABSTRACTCAMERA_HPP
#define APALINEA_EXTRAS_VISION_ABSTRACTCAMERA_HPP

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

        [[maybe_unused]] virtual void stop() final {
            if (!this->vStarted) {
                throw std::runtime_error("AbstractCamera is not started!");
            }

            this->internalStop();

            this->vStarted = false;
        }

        [[maybe_unused]] [[nodiscard]] virtual bool isStarted() const final{
            return this->vStarted;
        }

        [[nodiscard]] virtual Core::Type::Image getImage() const final{
            if (!this->vStarted) {
                throw std::runtime_error("AbstractCamera is not started!");
            }

            return this->getInternalImage();
        }

        virtual const Config& getConfig() const = 0;

        virtual void setConfig(Config&& config) = 0;

        virtual void setConfig(Config& config) = 0;

    protected:
        bool vStarted;

        virtual void internalStart() = 0;

        virtual void internalStop() = 0;

        [[nodiscard]] virtual Core::Type::Image getInternalImage() const = 0;
    };
} // Apalinea::Extras::Vision

#endif //APALINEA_EXTRAS_VISION_ABSTRACTCAMERA_HPP
