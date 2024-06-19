#ifndef APALINEA_CORE_TUPLE_TRAITS_HPP
#define APALINEA_CORE_TUPLE_TRAITS_HPP

#include <type_traits>

namespace Apalinea::Core::Tuple {
    template<typename Type, typename = void>
    struct HasTypeAnIdentifier : std::false_type {};

    template <typename Type>
    struct HasTypeAnIdentifier<Type, std::void_t<decltype(Type::IDENTIFIER)>> : std::true_type {};
} // Apalinea::Core::Tuple

#endif //APALINEA_CORE_TUPLE_TRAITS_HPP
