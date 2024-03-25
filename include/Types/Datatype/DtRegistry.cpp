//
// Created by SlepiK on 24.03.24.
//

#include "DtRegistry.hpp"

namespace Energyleaf::Stream::V1::Types::Datatype {
    std::unordered_map<DtRegistry::DtRegistryIdentifier , DtRegistry::DtRegistryIndex> DtRegistry::dtMap;
    DtRegistry::DtRegistryIndex DtRegistry::dtCurrentIndex = 0;
}