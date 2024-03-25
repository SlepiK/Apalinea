//
// Created by Simon Stahmer on 24.03.24.
//

#ifndef STREAM_V1_TYPES_DATATYPE_DTNUMBERS_HPP
#define STREAM_V1_TYPES_DATATYPE_DTNUMBERS_HPP

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
#include "DtBool.hpp"
#include "DtFloat.hpp"
#include "DtDouble.hpp"

#include "DtRegistry.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    class Numbers {
    public:
        static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseNumberDatatypes() {
            return numbers;
        }

        static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseFloatNumberDatatypes() {
            return floatnumbers;
        }

        static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseIntegerNumberDatatypes() {
            return integernumbers;
        }

        static bool isFloatNumber(DtRegistry::DtRegistryIdentifier dt) {
            return floatnumbers.contains(dt);
        }

    private:
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> numbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> floatnumbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> integernumbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> sintegernumbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> uintegernumbers;
    };

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::numbers{integernumbers};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::floatnumbers{DtFloat::IDENTIFIER,DtDouble::IDENTIFIER};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::integernumbers{DtInt::IDENTIFIER,DtInt8::IDENTIFIER,DtInt16::IDENTIFIER,
                                                                          DtInt32::IDENTIFIER, DtInt64::IDENTIFIER, DtUInt8::IDENTIFIER,
                                                                          DtUInt16::IDENTIFIER, DtUInt32::IDENTIFIER, DtUInt64::IDENTIFIER,DtSizeT::IDENTIFIER};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::uintegernumbers{DtUInt8::IDENTIFIER,
                                                                                 DtUInt16::IDENTIFIER, DtUInt32::IDENTIFIER, DtUInt64::IDENTIFIER,DtSizeT::IDENTIFIER};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::sintegernumbers{DtInt::IDENTIFIER,DtInt8::IDENTIFIER,DtInt16::IDENTIFIER,
                                                                                 DtInt32::IDENTIFIER, DtInt64::IDENTIFIER};

}

#endif //STREAM_V1_TYPES_DATATYPE_DTNUMBERS_HPP
