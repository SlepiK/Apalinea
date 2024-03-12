//
// Created by SlepiK on 16.02.2024.
//

#ifndef STREAM_V1_TUPLE_DITEM_HPP
#define STREAM_V1_TUPLE_DITEM_HPP

#include <string>
#include "IEvaluate.hpp"
#include "ItemType.hpp"

namespace Energyleaf::Stream::V1::Tuple {
    class DepItem : public IEvaluate {
    public:
        virtual ~DepItem() = default;
        [[nodiscard]] virtual std::unique_ptr<DepItem> copy() const = 0;
        [[nodiscard]] virtual const ItemType& getType() const = 0;
    };
}

#endif //STREAM_V1_TUPLE_DITEM_HPP
