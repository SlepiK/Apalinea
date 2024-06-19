#include "Core/Type/Datatype/DtRegistry.hpp"

namespace Apalinea::Core::Type::Datatype {
    std::unordered_map<DtRegistry::DtRegistryIdentifier , DtRegistry::DtRegistryIndex> DtRegistry::dtMap;
    DtRegistry::DtRegistryIndex DtRegistry::dtCurrentIndex = 0;
} // Apalinea::Core::Type::Datatype