//
// Created by SlepiK on 17.02.2024.
//

#ifndef STREAM_V1_TYPES_STRINGITEM_HPP
#define STREAM_V1_TYPES_STRINGITEM_HPP


#include <Types/Base/TBaseItem.hpp>
#include <Tuple/Item/Item.hpp>
#include <memory>
#include <Tuple/Item/ItemType.hpp>

namespace Energyleaf::Stream::V1::Types::Base {
class StringItem : public Energyleaf::Stream::V1::Tuple::Item {
    public:

        static const Tuple::ItemType TYPE;

        StringItem(std::string&& data) : vData(std::move(data)) {
        }

        [[nodiscard]] std::unique_ptr<Energyleaf::Stream::V1::Tuple::Item> copy() const override {
            return std::make_unique<StringItem>(*this);
        }

        void evaluate() override {
        }

        [[nodiscard]] const Tuple::ItemType& getType() const override {
            return TYPE;
        }

        [[nodiscard]] const std::string& getData() const {
            return this->vData;
        }
    private:
        std::string vData;
    };

    const Tuple::ItemType StringItem::TYPE = Tuple::iTString;
}

#endif //STREAM_V1_TYPES_STRINGITEM_HPP
