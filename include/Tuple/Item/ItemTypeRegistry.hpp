//
// Created by SlepiK on 21.02.2024.
//

#ifndef STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP
#define STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP

#include <vector>
#include <algorithm>
#include "ItemType.hpp"

namespace Energyleaf::Stream::V1::Tuple {
    class ItemTypeRegistry {
    public:
        ItemTypeRegistry() = delete;

        static void addItemType(const ItemType& type) {
            vRegistered.push_back(type);
        }

        static void removeItemType(const ItemType& type) {
            vRegistered.erase(std::remove(vRegistered.begin(), vRegistered.end(), type), vRegistered.end());
        }

        static void removeItemType(std::size_t index) {
            if (index < vRegistered.size()) {
                vRegistered.erase(vRegistered.begin() + static_cast<std::vector<ItemType>::difference_type>(index));
            }
        }

        static bool containsItemType(const ItemType& type) {
            return std::find(vRegistered.begin(), vRegistered.end(), type) != vRegistered.end();
        }

        static std::size_t getIndexOfType(const ItemType& type) {
            auto it = std::find(vRegistered.begin(), vRegistered.end(), type);
            if (it != vRegistered.end()) {
                return std::distance(vRegistered.begin(), it);
            }
            throw std::out_of_range("Given index is out of range");
        }
    private:
        static std::vector<ItemType> vRegistered;
    };

    //Load of default values!
    std::vector<ItemType> ItemTypeRegistry::vRegistered = {iTString,iTInt,iTFloat,iTDouble};
}

#endif //STREAM_V1_TUPLE_ITEM_ITEMTYPEREGISTRY_HPP
