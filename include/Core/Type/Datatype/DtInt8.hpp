#ifndef APALINEA_CORE_TYPE_DATATYPE_DTINT8_HPP
#define APALINEA_CORE_TYPE_DATATYPE_DTINT8_HPP

#include <cstdint>
#include <string_view>
#include <cmath>
#include "Core/Type/Datatype/IDt.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Core/Type/Datatype/DtInt.hpp"
#include "Core/Type/Datatype/DtInt16.hpp"
#include "Core/Type/Datatype/DtInt32.hpp"
#include "Core/Type/Datatype/DtInt64.hpp"
#include "Core/Type/Datatype/DtUInt8.hpp"
#include "Core/Type/Datatype/DtUInt16.hpp"
#include "Core/Type/Datatype/DtUInt32.hpp"
#include "Core/Type/Datatype/DtUInt64.hpp"
#include "Core/Type/Datatype/DtSizeT.hpp"
#include "Core/Type/Datatype/DtDouble.hpp"
#include "Core/Type/Datatype/DtBool.hpp"

namespace Apalinea::Core::Type::Datatype {
    class DtInt8 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt8"};

        explicit DtInt8() : IDt({IDENTIFIER}) {
        }

        explicit DtInt8(int8_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt8& operator=(const DtInt8 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Core::Type::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt8>(*this);
        }

        [[nodiscard]] virtual int8_t toInt8() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() == (static_cast<const DtInt8&>(other)).toInt8();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() != (static_cast<const DtInt8&>(other)).toInt8();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() < (static_cast<const DtInt8&>(other)).toInt8();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() > (static_cast<const DtInt8&>(other)).toInt8();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() <= (static_cast<const DtInt8&>(other)).toInt8();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt8() >= (static_cast<const DtInt8&>(other)).toInt8();
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
        int8_t data{};
    };
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_DTINT8_HPP
