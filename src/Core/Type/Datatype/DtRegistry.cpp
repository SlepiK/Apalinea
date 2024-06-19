//
// Created by SlepiK on 24.03.24.
//

#include "Core/Type/Datatype/DtRegistry.hpp"

namespace Apalinea::Core::Types::Datatype {
    std::unordered_map<DtRegistry::DtRegistryIdentifier , DtRegistry::DtRegistryIndex> DtRegistry::dtMap;
    DtRegistry::DtRegistryIndex DtRegistry::dtCurrentIndex = 0;
}