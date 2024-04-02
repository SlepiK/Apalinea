//
// Created by SlepiK on 24.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTFLOAT_HPP
#define STREAM_V1_TYPES_DATATYPE_DTFLOAT_HPP

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
#include "DtUInt32.hpp"
#include "DtUInt64.hpp"
#include "DtSizeT.hpp"
#include "DtBool.hpp"
#include "DtDouble.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtFloat : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtFloat"};

        DtFloat() : IDt(IDENTIFIER,{IDENTIFIER}) {
        }

        explicit DtFloat(float data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtFloat& operator=(const DtFloat &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtFloat>(*this);
        }

        [[nodiscard]] virtual float toFloat() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() == (static_cast<const DtFloat&>(other)).toFloat();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() != (static_cast<const DtFloat&>(other)).toFloat();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() < (static_cast<const DtFloat&>(other)).toFloat();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() > (static_cast<const DtFloat&>(other)).toFloat();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() <= (static_cast<const DtFloat&>(other)).toFloat();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toFloat() >= (static_cast<const DtFloat&>(other)).toFloat();
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
        float data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTFLOAT_HPP
