//
// Created by SlepiK on 21.02.2024.
//

#ifndef STREAM_V1_TUPLE_ITEM_ITEMTYPE_HPP
#define STREAM_V1_TUPLE_ITEM_ITEMTYPE_HPP

#include <string>
#include <string_view>

namespace Energyleaf::Stream::V1::Tuple {
    class ItemType {
    public:
        explicit ItemType(std::string&& name) : vName(std::move(name)) {
        }

        bool operator==(const ItemType& other) const {
            return this->vName == other.vName;
        }

        [[nodiscard]] std::string_view getName() const {
            return this->vName;
        }
    private:
        std::string vName;
    };

    static const ItemType iTString = ItemType("string");
    static const ItemType iTInt = ItemType("int");
    static const ItemType iTFloat = ItemType("float");
    static const ItemType iTDouble = ItemType("double");
}

#endif //STREAM_V1_TUPLE_ITEM_ITEMTYPE_HPP
