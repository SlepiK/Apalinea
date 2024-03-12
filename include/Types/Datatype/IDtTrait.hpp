//
// Created by SlepiK on 17.02.2024.
//

#ifndef STREAM_V1_TUPLE_ITEMVISITOR_HPP
#define STREAM_V1_TUPLE_ITEMVISITOR_HPP

#include <type_traits>
#include "Tuple/Item/DepItem.hpp"

namespace Energyleaf::Stream::V1::Tuple {

    template<typename Type, typename = void>
    struct HasTypeAnIdentifier : std::false_type {};

    template <typename Type>
    struct HasTypeAnIdentifier<Type, std::void_t<decltype(Type::IDENTIFIER)>> : std::true_type {};

}

#endif //STREAM_V1_TUPLE_ITEMVISITOR_HPP
