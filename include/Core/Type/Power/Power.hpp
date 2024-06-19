//
// Created by SlepiK on 29.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_POWERTYPE_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_POWERTYPE_HPP

#include <utility>

namespace Apalinea::Core::Types {
    class Power {
    public:

        explicit Power()
            : watt(0) {
        }

        explicit Power(float watt)
            : watt(watt) {
        }

        explicit Power(float&& watt)
            : watt(watt){
        }

        Power(Power &&other)
        noexcept: watt(other.watt) {
        }

        Power(const Power& other) {
            this->watt = other.watt;
        }

        virtual ~Power() = default;

        Power& operator=(Power&& other) noexcept {
            this->watt = other.watt;
            return *this;
        }

        Power& operator=(const Power& other) {
            this->watt = other.watt;
            return *this;
        }

        Power& operator=(float&& other) noexcept {
            this->watt = other;
            return *this;
        }

        Power& operator=(const float& other) {
            this->watt = other;
            return *this;
        }

        [[nodiscard]] float getPower() const {
            return this->watt;
        }
    private:
        float watt;
    };
}

#endif //ENERGYLEAF_STREAM_V1_TYPES_POWERTYPE_HPP
