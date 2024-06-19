#ifndef APALINEA_CORE_TYPE_POWERTYPE_HPP
#define APALINEA_CORE_TYPE_POWERTYPE_HPP

#include <utility>

namespace Apalinea::Core::Type {
    class [[maybe_unused]] Power {
    public:

        explicit Power()
            : watt(0) {
        }

        [[maybe_unused]] explicit Power(float watt)
            : watt(watt) {
        }

        [[maybe_unused]] explicit Power(float&& watt)
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

        Power& operator=(const Power& other) = default;

        Power& operator=(float&& other) noexcept {
            this->watt = other;
            return *this;
        }

        Power& operator=(const float& other) {
            this->watt = other;
            return *this;
        }

        [[maybe_unused]] [[nodiscard]] float getPower() const {
            return this->watt;
        }

    private:
        float watt;
    };
} // Apalinea::Core::Type

#endif //APALINEA_CORE_TYPE_POWERTYPE_HPP
