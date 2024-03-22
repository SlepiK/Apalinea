//
// Created by SlepiK on 12.03.2024.
//

#ifndef STREAM_V1_TYPES_DATATYPE_IDT_HPP
#define STREAM_V1_TYPES_DATATYPE_IDT_HPP

#include <unordered_set>
#include <string_view>
#include <vector>
#include <memory>
#include "DtRegistry.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {

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
    private:
        //ToDo: Verify in future if multiple datatypes are needed or even possible, due to some restrictions.
        const std::unordered_set<DtRegistry::DtRegistryIdentifier> datatypes;
    };
}

#endif //STREAM_V1_TYPES_DATATYPE_IDT_HPP
