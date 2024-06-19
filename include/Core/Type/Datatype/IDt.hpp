#ifndef APALINEA_CORE_TYPE_DATATYPE_IDT_HPP
#define APALINEA_CORE_TYPE_DATATYPE_IDT_HPP

#include <unordered_set>
#include <string_view>
#include <vector>
#include <memory>
#include "Core/Type/Datatype/DtRegistry.hpp"

namespace Apalinea::Core::Type::Datatype {

    class IDt {
    public:
        explicit IDt(DtRegistry::DtRegistryIdentifier identifier) : datatypes({identifier}) {
            DtRegistry::reg(identifier);
        }
        explicit IDt(DtRegistry::DtRegistryIdentifier identifier, std::vector<DtRegistry::DtRegistryIdentifier> datatypes) : datatypes(datatypes.begin(),datatypes.end()) {
            DtRegistry::reg(identifier);
        }
        virtual ~IDt() = default;
        [[nodiscard]] virtual std::unique_ptr<IDt> copy() const = 0;

        bool isBasedOn(DtRegistry::DtRegistryIdentifier datatype) const {
            return this->datatypes.find(datatype) != this->datatypes.end();
        }

        [[nodiscard]] virtual DtRegistry::DtRegistryIdentifier getIdentifier() const = 0;

        virtual bool operator==(const IDt& other) const = 0;
        virtual bool operator!=(const IDt& other) const = 0;
        virtual bool operator<(const IDt& other) const = 0;
        virtual bool operator>(const IDt& other) const = 0;
        virtual bool operator<=(const IDt& other) const = 0;
        virtual bool operator>=(const IDt& other) const = 0;

        virtual IDt* operator+(const IDt& other) const = 0;
        virtual IDt* operator-(const IDt& other) const = 0;
        virtual IDt* operator*(const IDt& other) const = 0;
        virtual IDt* operator/(const IDt& other) const = 0;
        virtual IDt* operator^(const IDt& other) const = 0;
        virtual IDt* operator%(const IDt& other) const = 0;

    private:
        const std::unordered_set<DtRegistry::DtRegistryIdentifier> datatypes;
    };
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_IDT_HPP
