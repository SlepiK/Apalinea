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
    class [[maybe_unused]] Numbers {
    public:
        [[maybe_unused]] static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseNumberDatatypes() {
            return numbers;
        }

        [[maybe_unused]] static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseFloatNumberDatatypes() {
            return floatnumbers;
        }

        [[maybe_unused]] static const std::unordered_set<DtRegistry::DtRegistryIdentifier>& getBaseIntegerNumberDatatypes() {
            return integernumbers;
        }

        [[maybe_unused]] static bool isFloatNumber(DtRegistry::DtRegistryIdentifier dt) {
            return floatnumbers.contains(dt);
        }

    private:
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> numbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> floatnumbers;
        static std::unordered_set<DtRegistry::DtRegistryIdentifier> integernumbers;
        [[maybe_unused]] static std::unordered_set<DtRegistry::DtRegistryIdentifier> sintegernumbers;
        [[maybe_unused]] static std::unordered_set<DtRegistry::DtRegistryIdentifier> uintegernumbers;
    };
} // Apalinea::Core::Type::Datatype

#endif //APALINEA_CORE_TYPE_DATATYPE_DTNUMBERS_HPP
