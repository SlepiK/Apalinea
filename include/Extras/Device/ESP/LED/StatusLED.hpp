//
// Created by SlepiK on 30.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_STATUSLED_HPP
#define ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_STATUSLED_HPP

#include "AbstractLED.hpp"

namespace Energyleaf::Stream::V1::Extras::Device::ESP::LED {
    class StatusLED : public AbstractLED {
    public:
        explicit StatusLED(std::uint8_t pin) : AbstractLED(pin) {
#ifdef ENERGYLEAF_ESP
            pinMode(this->vPin, OUTPUT);
#endif
        }

        ~StatusLED() override = default;

    private:
    protected:
        void update() override{
#ifdef ENERGYLEAF_ESP
            digitalWrite(this->vPin, this->vEnable ? LOW : HIGH);
#endif
        }
    };
}

#endif //ENERGYLEAF_STREAM_V1_EXTRAS_DEVICE_ESP_LED_STATUSLED_HPP