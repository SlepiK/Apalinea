//
// Created by SlepiK on 30.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_CAMERALED_HPP
#define ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_CAMERALED_HPP

#include "AbstractLED.hpp"

namespace Energyleaf::Stream::V1::Extras::Device::ESP::LED {
    class CameraLED : public AbstractLED {
    public:
        CameraLED(std::uint8_t pin, std::uint8_t channel, std::uint32_t duty)
                : AbstractLED(pin), vChannel(channel), vDuty(duty) {
#ifdef ENERGYLEAF_ESP
            ledcSetup(this->vChannel, 5000, 8);
            ledcAttachPin(this->vPin, this->vChannel);
#endif
        }

        ~CameraLED() override = default;

        void setDuty(std::uint32_t&& duty) {
            this->vDuty = duty;
            this->update();
        }

        [[nodiscard]] std::uint32_t getDuty() const {
            return this->vDuty;
        }

    private:
        const std::uint8_t vChannel;
        std::uint32_t vDuty;
        static constexpr int CONFIG_LED_MAX_INTENSITY = 255;

    protected:
        void update() override {
            int duty = this->vEnable ? this->vDuty : 0;
            if (this->vEnable && (this->vDuty > CONFIG_LED_MAX_INTENSITY)) {
                duty = CONFIG_LED_MAX_INTENSITY;
            }
#ifdef ENERGYLEAF_ESP
            ledcWrite(this->vChannel, duty);
#endif
        }
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_CAMERALED_HPP