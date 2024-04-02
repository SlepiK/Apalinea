//
// Created by SlepiK on 24.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTDOUBLE_HPP
#define STREAM_V1_TYPES_DATATYPE_DTDOUBLE_HPP

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
#include "DtFloat.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtDouble : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtDouble"};

        DtDouble() : IDt(IDENTIFIER,{IDENTIFIER}) {
        }

        explicit DtDouble(double data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtDouble& operator=(const DtDouble &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtDouble>(*this);
        }

        [[nodiscard]] virtual double toDouble() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() == (static_cast<const DtDouble&>(other)).toDouble();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() != (static_cast<const DtDouble&>(other)).toDouble();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() < (static_cast<const DtDouble&>(other)).toDouble();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() > (static_cast<const DtDouble&>(other)).toDouble();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() <= (static_cast<const DtDouble&>(other)).toDouble();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toDouble() >= (static_cast<const DtDouble&>(other)).toDouble();
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
        double data{};
    private:
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTDOUBLE_HPP
