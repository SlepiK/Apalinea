#ifndef APALINEA_CORE_TYPE_DATATYPE_DTINT16_HPP
#define APALINEA_CORE_TYPE_DATATYPE_DTINT16_HPP

#include <cstdint>
#include <string_view>
#include <cmath>
#include "Core/Type/Datatype/IDt.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Core/Type/Datatype/DtInt.hpp"
#include "Core/Type/Datatype/DtInt8.hpp"
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
    class DtInt16 : public IDt {
    public:
        static constexpr DtRegistry::DtRegistryIdentifier IDENTIFIER{"DtInt16"};

        explicit DtInt16() : IDt({IDENTIFIER}) {
        }

        explicit DtInt16(int16_t data) : IDt({IDENTIFIER}), data(data) {
        }

        [[nodiscard]] DtRegistry::DtRegistryIdentifier getIdentifier() const override {
            return IDENTIFIER;
        }

        DtInt16& operator=(const DtInt16 &other) {
            if(&other != this) {
                this->data = other.data;
            }
            return *this;
        }

        [[nodiscard]] std::unique_ptr<Core::Type::Datatype::IDt> copy() const override {
            return std::make_unique<DtInt16>(*this);
        }

        [[nodiscard]] virtual int16_t toInt16() const {
            return this->data;
        }

        bool operator==(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() == (static_cast<const DtInt16&>(other)).toInt16();
            }
            return false;
        }

        bool operator!=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() != (static_cast<const DtInt16&>(other)).toInt16();
            }
            return false;
        }

        bool operator<(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() < (static_cast<const DtInt16&>(other)).toInt16();
            }
            return false;
        }

        bool operator>(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() > (static_cast<const DtInt16&>(other)).toInt16();
            }
            return false;
        }

        bool operator<=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() <= (static_cast<const DtInt16&>(other)).toInt16();
            }
            return false;
        }

        bool operator>=(const IDt& other) const override {
            if(other.getIdentifier() == this->getIdentifier()) {
                return this->toInt16() >= (static_cast<const DtInt16&>(other)).toInt16();
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
        int16_t data{};
    };
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_DTINT16_HPP
