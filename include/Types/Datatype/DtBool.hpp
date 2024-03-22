//
// Created by SlepiK on 20.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP
#define STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP

#include <string_view>
#include "IDt.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class DtBool : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtBool"};

        DtBool() : IDt(IDENTIFIER,{IDENTIFIER}) {
        }

        explicit DtBool(int &&data) : IDt({IDENTIFIER}), data(data) {
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
    protected:
        bool data{};
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP
