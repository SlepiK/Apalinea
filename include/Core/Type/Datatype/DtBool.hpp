//
// Created by SlepiK on 20.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP
#define STREAM_V1_TYPES_DATATYPE_DTBOOL_HPP

#include <string_view>
#include <cmath>
#include "Core/Type/Datatype/IDt.hpp"
#include "Core/Exception/NotImplementedException.hpp"
#include "Core/Type/Datatype/DtInt.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"
#include "Core/Type/Datatype/DtInt16.hpp"
#include "Core/Type/Datatype/DtInt32.hpp"
#include "Core/Type/Datatype/DtInt64.hpp"
#include "Core/Type/Datatype/DtUInt8.hpp"
#include "Core/Type/Datatype/DtUInt16.hpp"
#include "Core/Type/Datatype/DtUInt32.hpp"
#include "Core/Type/Datatype/DtUInt64.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Core/Type/Datatype/DtDouble.hpp"

namespace Apalinea::Core::Types::Datatype {
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

        [[nodiscard]] std::unique_ptr<Core::Types::Datatype::IDt> copy() const override {
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
