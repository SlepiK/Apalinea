//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
#define STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP

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
#include "DtUInt16.hpp"
#include "DtUInt64.hpp"
#include "DtSizeT.hpp"
#include "DtBool.hpp"
#include "DtDouble.hpp"
#include "DtFloat.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtUInt32 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtUInt32"};

        explicit DtUInt32() : IDt({IDENTIFIER}) {
        }

        explicit DtUInt32(uint32_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtUInt32& operator=(const DtUInt32 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtUInt32>(*this);
        }

        [[nodiscard]] virtual uint32_t toUInt32() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() == (static_cast<const DtUInt32&>(other)).toUInt32();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() != (static_cast<const DtUInt32&>(other)).toUInt32();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() < (static_cast<const DtUInt32&>(other)).toUInt32();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() > (static_cast<const DtUInt32&>(other)).toUInt32();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() <= (static_cast<const DtUInt32&>(other)).toUInt32();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toUInt32() >= (static_cast<const DtUInt32&>(other)).toUInt32();
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
        uint32_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTUINT32_HPP
