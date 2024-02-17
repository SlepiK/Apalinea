//
// Created by SlepiK on 16.02.2024.
//

#ifndef STREAM_V1_TUPLE_IITEM_HPP
#define STREAM_V1_TUPLE_IITEM_HPP

#include <string>
#include "IEvaluate.hpp"

namespace Energyleaf::Stream::V1::Tuple {
    class Item : public IEvaluate {
    public:
        virtual ~Item() = default;
        [[nodiscard]] virtual std::unique_ptr<Item> copy() const = 0;
        [[nodiscard]] virtual const std::string& getName() const = 0;
    };
}

#endif //STREAM_V1_TUPLE_IITEM_HPP
