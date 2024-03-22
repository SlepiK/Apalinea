//
// Created by SlepiK on 11.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTINT_HPP
#define STREAM_V1_TYPES_DATATYPE_DTINT_HPP

#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtInt : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt"};

        DtInt() : IDt(IDENTIFIER,{IDENTIFIER}) {
        }

        explicit DtInt(int &&data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt& operator=(const DtInt &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Types::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt>(*this);
        }

        [[nodiscard]] virtual int toInt() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() == (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() != (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() < (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() > (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() <= (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt() >= (static_cast<const DtInt&>(other)).toInt();
            }
            return false;
        }
    protected:
        int data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTINT_HPP
