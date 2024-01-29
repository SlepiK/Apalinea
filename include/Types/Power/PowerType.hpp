//
// Created by SlepiK on 29.01.24.
//

#ifndef ENERGYLEAF_STREAM_V1_TYPES_POWERTYPE_HPP
#define ENERGYLEAF_STREAM_V1_TYPES_POWERTYPE_HPP

#include <utility>

namespace Energyleaf::Stream::V1::Types {
    /**
     * This class represents a empty object or empty type, because void as type is not direct allowed in this library!
     */
    class PowerType {
    public:

        explicit PowerType()
            : watt(0) {
        }

        explicit PowerType(float watt)
            : watt(watt) {
        }

        explicit PowerType(float&& watt)
            : watt(watt){
        }

        PowerType(PowerType &&other)
        noexcept: watt(other.watt) {
        }

        PowerType(const PowerType& other) {
            this->watt = other.watt;
        }

        virtual ~PowerType() = default;

        PowerType& operator=(PowerType&& other) noexcept {
            this->watt = other.watt;
            return *this;
        }

        PowerType& operator=(const PowerType& other) {
            this->watt = other.watt;
            return *this;
        }

        PowerType& operator=(float&& other) noexcept {
            this->watt = other;
            return *this;
        }

        PowerType& operator=(const float& other) {
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
