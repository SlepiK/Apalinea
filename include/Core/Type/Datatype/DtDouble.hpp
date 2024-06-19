#ifndef APALINEA_CORE_TYPE_DATATYPE_DTDOUBLE_HPP
#define APALINEA_CORE_TYPE_DATATYPE_DTDOUBLE_HPP

#include <string_view>
#include <cmath>
#include "Core/Type/Datatype/IDt.hpp"
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
#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Core::Type::Datatype {
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

        [[nodiscard]] std::unique_ptr<Core::Type::Datatype::IDt> copy() const override {
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
    };
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_DTDOUBLE_HPP
