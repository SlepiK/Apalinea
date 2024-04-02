//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP

#include <cstdint>
#include <string_view>
#include <cmath>
#include "IDt.hpp"

#include "DtInt.hpp"
#include "DtInt8.hpp"
#include "DtInt16.hpp"
#include "DtInt32.hpp"
#include "DtInt64.hpp"
#include "DtUInt8.hpp"
#include "DtUInt32.hpp"
#include "DtUInt64.hpp"
#include "DtSizeT.hpp"
#include "DtBool.hpp"
#include "DtDouble.hpp"
#include "DtFloat.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt16 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtUInt16"};

        explicit DtUInt16() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt16(uint16_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtUInt16& operator=(const DtUInt16 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt16>(*this);
        }

        [[nodiscard]] virtual uint16_t toUInt16() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() == (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() != (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() < (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() > (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() <= (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt16() >= (static_cast<const DtUInt16&>(other)).toUInt16();
            }
            return false;
        }

        IDt* operator+(const IDt& other) const override;
        IDt* operator-(const IDt& other) const override;
        IDt* operator*(const IDt& other) const override;
        IDt* operator/(const IDt& other) const override;
        IDt* operator^(const IDt& other) const override;
        IDt* operator%(const IDt& other) const override;
    protected:
        uint16_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT16_HPP
