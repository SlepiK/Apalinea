#ifndef APALINEA_CORE_TYPE_DATATYPE_DTNUMBERS_HPP
#define APALINEA_CORE_TYPE_DATATYPE_DTNUMBERS_HPP

#include "Core/Type/Datatype/DtRegistry.hpp"
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
#include "Core/Type/Datatype/DtBool.hpp"
#include "Core/Type/Datatype/DtFloat.hpp"
#include "Core/Type/Datatype/DtDouble.hpp"

namespace Apalinea::Core::Type::Datatype {
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
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_DTNUMBERS_HPP
