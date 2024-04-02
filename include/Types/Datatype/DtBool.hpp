//
// Created by SlepiK on 20.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP
#define STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP

#include <string_view>
#include <cmath>
#include "IDt.hpp"
#include "Exception/NotImplementedException.hpp"

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
#include "DtFloat.hpp"
#include "DtDouble.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtBool : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtBool"};

        DtBool() : IDt(IDENTIFIER,{IDENTIFIER}) {
        }

        explicit DtBool(bool data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtBool& operator=(const DtBool &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtBool>(*this);
        }

        [[nodiscard]] virtual int toBool() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() == (static_cast<const DtBool&>(other)).toBool();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() != (static_cast<const DtBool&>(other)).toBool();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() < (static_cast<const DtBool&>(other)).toBool();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() > (static_cast<const DtBool&>(other)).toBool();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() <= (static_cast<const DtBool&>(other)).toBool();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toBool() >= (static_cast<const DtBool&>(other)).toBool();
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
        bool data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP
