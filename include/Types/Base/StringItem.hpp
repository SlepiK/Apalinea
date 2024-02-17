//
// Created by SlepiK on 17.02.2024.
//

#ifndef STREAM_V1_TYPES_STRINGITEM_HPP
#define STREAM_V1_TYPES_STRINGITEM_HPP

#include <Types/Base/TBaseItem.hpp>
#include <Tuple/Item/Item.hpp>
#include <memory>

namespace Energyleaf::Stream::V1::Types::Base {
class StringItem final : public Energyleaf::Stream::V1::Types::Base::TBaseItem<std::string> {
    public:

        constexpr static const std::string NAME = "StringItem";

        StringItem(std::string&& data) : Energyleaf::Stream::V1::Types::Base::TBaseItem<std::string>(std::move(data)) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Tuple::Item> copy() const override {
            return std::make_unique<StringItem>(*this);
        }

        [[nodiscard]] const std::string& getName() const override {
            return NAME;
        }

        void evaluate() override {
        }
    };
}

#endif //STREAM_V1_TYPES_STRINGITEM_HPP
