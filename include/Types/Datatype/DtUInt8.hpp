//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP

#include <cstdint>
#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt8 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtUInt8"};

        explicit DtUInt8() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt8(uint8_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtUInt8& operator=(const DtUInt8 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt8>(*this);
        }

        [[nodiscard]] virtual uint8_t toUInt8() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() == (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() != (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() < (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() > (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() <= (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt8() >= (static_cast<const DtUInt8&>(other)).toUInt8();
            }
            return false;
        }
    protected:
        uint8_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT8_HPP
