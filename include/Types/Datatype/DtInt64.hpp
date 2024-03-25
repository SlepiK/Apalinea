//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT64_HPP

#include <cstdint>
#include <string_view>
#include <cmath>
#include "IDt.hpp"

#include "DtInt.hpp"
#include "DtInt8.hpp"
#include "DtInt16.hpp"
#include "DtInt32.hpp"
#include "DtUInt8.hpp"
#include "DtUInt16.hpp"
#include "DtUInt32.hpp"
#include "DtUInt64.hpp"
#include "DtSizeT.hpp"
#include "DtBool.hpp"
#include "DtDouble.hpp"
#include "DtFloat.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt64 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt64"};

        explicit DtInt64() : IDt({IDENTIFIER}) {
        }

        explicit DtInt64(int64_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt64& operator=(const DtInt64 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt64>(*this);
        }

        [[nodiscard]] virtual int64_t toInt64() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() == (static_cast<const DtInt64&>(other)).toInt64();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() != (static_cast<const DtInt64&>(other)).toInt64();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() < (static_cast<const DtInt64&>(other)).toInt64();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() > (static_cast<const DtInt64&>(other)).toInt64();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() <= (static_cast<const DtInt64&>(other)).toInt64();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt64() >= (static_cast<const DtInt64&>(other)).toInt64();
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
        int64_t data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT64_HPP
