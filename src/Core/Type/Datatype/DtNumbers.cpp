#include "Core/Type/Datatype/DtNumbers.hpp"

namespace Apalinea::Core::Type::Datatype {
    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::floatnumbers{DtFloat::IDENTIFIER,DtDouble::IDENTIFIER};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::integernumbers{DtInt::IDENTIFIER,DtInt8::IDENTIFIER,DtInt16::IDENTIFIER,
                                                                                 DtInt32::IDENTIFIER, DtInt64::IDENTIFIER, DtUInt8::IDENTIFIER,
                                                                                 DtUInt16::IDENTIFIER, DtUInt32::IDENTIFIER, DtUInt64::IDENTIFIER,DtSizeT::IDENTIFIER};

    [[maybe_unused]] std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::uintegernumbers{DtUInt8::IDENTIFIER,
                                                                                                   DtUInt16::IDENTIFIER, DtUInt32::IDENTIFIER, DtUInt64::IDENTIFIER,DtSizeT::IDENTIFIER};

    [[maybe_unused]] std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::sintegernumbers{DtInt::IDENTIFIER,DtInt8::IDENTIFIER,DtInt16::IDENTIFIER,
                                                                                                   DtInt32::IDENTIFIER, DtInt64::IDENTIFIER};

    std::unordered_set<DtRegistry::DtRegistryIdentifier> Numbers::numbers{integernumbers};
} // Apalinea::Core::Type::Datatype