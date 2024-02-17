//
// Created by SlepiK on 17.02.2024.
//

#ifndef STREAM_V1_TUPLE_ITEMVISITOR_HPP
#define STREAM_V1_TUPLE_ITEMVISITOR_HPP

#include <type_traits>
#include "Item.hpp"

namespace Energyleaf::Stream::V1::Tuple {

    template<typename T, typename = void>
    struct HasItemAnName : std::false_type {};

    template <typename T>
    struct HasItemAnName<T, std::void_t<decltype(T::NAME)>> : std::is_base_of<Item, T> {};

}

#endif //STREAM_V1_TUPLE_ITEMVISITOR_HPP
